  var gl;
  function initGL(canvas) {
    try {
      gl = canvas.getContext("experimental-webgl");
      gl.viewportWidth = canvas.width;
      gl.viewportHeight = canvas.height;
    } catch(e) {
    }
    if (!gl) {
      alert("Не удалось инициализировать WebGL. Возможно Ваш браузер не поддерживает WebGL.");
    }
  }

  function setMatrixUniforms(m1,m2) {
    gl.uniformMatrix4fv(shaderProgram.pMatrixUniform, false, new Float32Array(flatten(m1)));
    gl.uniformMatrix4fv(shaderProgram.mvMatrixUniform, false, new Float32Array(flatten(m2)));
	var normalMatrix = transpose(inverse(m2));
    gl.uniformMatrix4fv(shaderProgram.nMatrixUniform, false, new Float32Array(flatten(normalMatrix)));
}

  function handleLoadedTexture(texture) {
    gl.bindTexture(gl.TEXTURE_2D, texture);
    gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, true);
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, gl.RGBA, gl.UNSIGNED_BYTE, texture.image);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST);
    gl.bindTexture(gl.TEXTURE_2D, null);
  }
  
  var aTexture;
  function initTexture() {
    aTexture = gl.createTexture();
    aTexture.image = new Image();
    aTexture.image.onload = function() {
      handleLoadedTexture(aTexture)
    }

    aTexture.image.src = "texture.png";
  }
  
  var currentlyPressedKeys = Object();

  function handleKeyDown(event) {
    currentlyPressedKeys[event.keyCode] = true;
  }

  function handleKeyUp(event) {
    currentlyPressedKeys[event.keyCode] = false;
  }

  function handleKeys() {
  
    if (currentlyPressedKeys[69]){
      moving += 0.5;
    }
	if (currentlyPressedKeys[81]) {
      moving -= 0.5;
    }
  
    if (currentlyPressedKeys[65]) {
      // Left cursor key
      ang_y += 2.0;
    }
    if (currentlyPressedKeys[68]) {
      // Right cursor key
      ang_y -= 2.0;
    }
	if (currentlyPressedKeys[87]) {
      // Up cursor key
      ang_x += 2.0;
    }
    if (currentlyPressedKeys[83]) {
      // Down cursor key
      ang_x -= 2.0;
    }
  } 
 
var ang_x=0;
var ang_y=0;
var moving=0.0;

function drawScene() {
	var pMatrix;
	var mvMatrix;
	var nMatrix;
	var mt,mr_x,m_y;
    gl.viewport(0, 0, gl.viewportWidth, gl.viewportHeight);
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
	
	
    gl.uniform1i(shaderProgram.showSpecularHighlightsUniform, 1.0);

    gl.uniform1i(shaderProgram.useLightingUniform, 1.0);
    gl.uniform3f(shaderProgram.ambientColorUniform,0.2,0.2,0.2);

    gl.uniform3f(shaderProgram.pointLightingLocationUniform,0.0,5.0,5.0);

    gl.uniform3f(shaderProgram.pointLightingSpecularColorUniform,0.8,0.8,0.8);

    gl.uniform3f(shaderProgram.pointLightingDiffuseColorUniform,0.8,0.8,0.8);
	
	
	if (modelVertexPositionBuffer == null || modelVertexNormalBuffer == null || modelVertexTextureCoordBuffer == null || modelVertexIndexBuffer == null) {
      return;
    }
	
	pMatrix = matrix4_identity(); 
    pMatrix = matrix4_perspective(45, gl.viewportWidth / gl.viewportHeight, 0.1, 100.0);

	mvMatrix = matrix4_identity();
	mt = matrix4_translation([0.0, -1.0, -15.0+moving]);

	mr_y = matrix4_Rotation(degToRad(ang_y),[0.0,1.0,0.0]);
	mr_x = matrix4_Rotation(degToRad(ang_x),[1.0,0.0,0.0]);
	
	mvMatrix = mulMatrixMatrix4(mvMatrix,mr_x);
	mvMatrix = mulMatrixMatrix4(mvMatrix,mr_y);
	mvMatrix = mulMatrixMatrix4(mvMatrix,mt);

    gl.bindBuffer(gl.ARRAY_BUFFER, modelVertexPositionBuffer);
    gl.vertexAttribPointer(shaderProgram.vertexPositionAttribute, modelVertexPositionBuffer.itemSize, gl.FLOAT, false, 0, 0);

    gl.bindBuffer(gl.ARRAY_BUFFER, modelVertexTextureCoordBuffer);
    gl.vertexAttribPointer(shaderProgram.textureCoordAttribute, modelVertexTextureCoordBuffer.itemSize, gl.FLOAT, false, 0, 0);

	gl.bindBuffer(gl.ARRAY_BUFFER, modelVertexNormalBuffer);
    gl.vertexAttribPointer(shaderProgram.vertexNormalAttribute, modelVertexNormalBuffer.itemSize, gl.FLOAT, false, 0, 0);
	
    gl.activeTexture(gl.TEXTURE0);
    gl.bindTexture(gl.TEXTURE_2D, aTexture);
    gl.uniform1i(shaderProgram.samplerUniform, 0);
	
	gl.uniform1f(shaderProgram.materialShininessUniform, 1.0);
	
    gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, modelVertexIndexBuffer);
    setMatrixUniforms(pMatrix,mvMatrix);
    gl.drawElements(gl.TRIANGLES, modelVertexIndexBuffer.numItems, gl.UNSIGNED_SHORT, 0);
}

  function running() {
    handleKeys();
    drawScene();
  }
  
	function webGLStart() {
    var canvas = document.getElementById("app-canvas");
    initGL(canvas);
    initShaders();
	initTexture();
	
	loadModel("models/"+document.getElementById("model").value+"/model.obj");
	
    gl.clearColor(0.0, 0.0, 0.0, 1.0);
    gl.clearDepth(1.0);
    gl.enable(gl.DEPTH_TEST);
    gl.depthFunc(gl.LEQUAL);
	
	document.onkeydown = handleKeyDown;
    document.onkeyup = handleKeyUp;
    setInterval(running, 15);
  }