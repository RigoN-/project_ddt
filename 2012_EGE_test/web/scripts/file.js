/*function doLoadObj(modelData)
{
    vertexArray = [ ];
    normalArray = [ ];
    modelDataureArray = [ ];
    indexArray = [ ];

    var vertex = [ ];
    var normal = [ ];
    var modelDataure = [ ];
    var facemap = { };
    var index = 0;

    var groups = { };
    var currentGroup = [-1, 0];
    groups["_unnamed"] = currentGroup;

    var lines = modelData.split("\n");
    for (var lineIndex in lines) {
        var line = lines[lineIndex].replace(/[ \t]+/g, " ").replace(/\s\s*$/, "");

        if (line[0] == "#")
            continue;
			
        var array = line.split(" ");
        if (array[0] == "g") {
            // new group
            currentGroup = [indexArray.length, 0];
            groups[array[1]] = currentGroup;
        }
        else if (array[0] == "v") {
            // vertex
            vertex.push(parseFloat(array[1]).toFixed(6));
            vertex.push(parseFloat(array[2]).toFixed(6));
            vertex.push(parseFloat(array[3]).toFixed(6));
        }
        else if (array[0] == "vt") {
            // normal
            modelDataure.push(parseFloat(array[1]).toFixed(6));
            modelDataure.push(parseFloat(array[2]).toFixed(6));
        }
        else if (array[0] == "vn") {
            // normal
            normal.push(parseFloat(array[1]).toFixed(6));
            normal.push(parseFloat(array[2]).toFixed(6));
            normal.push(parseFloat(array[3]).toFixed(6));
        }
        else if (array[0] == "f") {
            // face
            if (array.length != 4) {
                continue;
            }

            for (var i = 1; i < 4; ++i) {
                if (!(array[i] in facemap)) {
                    // add a new entry to the map and arrays
                    var f = array[i].split("/");
                    var vtx, nor, tex;

                    if (f.length == 1) {
                        vtx = parseInt(f[0]) - 1;
                        nor = vtx;
                        tex = vtx;
                    }
                    else if (f.length = 3) {
                        vtx = parseInt(f[0]) - 1;
                        tex = parseInt(f[1]) - 1;
                        nor = parseInt(f[2]) - 1;
                    }
                    else {
                        return null;
                    }

                    // do the vertices
                    var x = 0;
                    var y = 0;
                    var z = 0;
                    if (vtx * 3 + 2 < vertex.length) {
                        x = vertex[vtx*3];
                        y = vertex[vtx*3+1];
                        z = vertex[vtx*3+2];
                    }
                    vertexArray.push(x);
					
                    vertexArray.push(y);
                    vertexArray.push(z);

                    // do the modelDataures
                    x = 0;
                    y = 0;
                    if (tex * 2 + 1 < modelDataure.length) {
                        x = modelDataure[tex*2];
                        y = modelDataure[tex*2+1];
                    }
                    modelDataureArray.push(x);
                    modelDataureArray.push(y);

                    // do the normals
                    x = 0;
                    y = 0;
                    z = 1;
                    if (nor * 3 + 2 < normal.length) {
                        x = normal[nor*3];
                        y = normal[nor*3+1];
                        z = normal[nor*3+2];
                    }
                    normalArray.push(x);
                    normalArray.push(y);
                    normalArray.push(z);

                    facemap[array[i]] = index++;
                }

                indexArray.push(facemap[array[i]]);
                currentGroup[1]++;
            }
        }
	
    }
	
    modelVertexNormalBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, modelVertexNormalBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(normalArray), gl.STATIC_DRAW);
    modelVertexNormalBuffer.itemSize = 3;
    modelVertexNormalBuffer.numItems = normalArray.length / 3;

    modelVertexTextureCoordBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, modelVertexTextureCoordBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(modelDataureArray), gl.STATIC_DRAW);
    modelVertexTextureCoordBuffer.itemSize = 2;
    modelVertexTextureCoordBuffer.numItems = modelDataureArray.length / 2;

    modelVertexPositionBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, modelVertexPositionBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(vertexArray), gl.STATIC_DRAW);
    modelVertexPositionBuffer.itemSize = 3;
    modelVertexPositionBuffer.numItems = vertexArray.length / 3;

    modelVertexIndexBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, modelVertexIndexBuffer);
    gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, new Uint16Array(indexArray), gl.STREAM_DRAW);
    modelVertexIndexBuffer.itemSize = 1;
    modelVertexIndexBuffer.numItems = indexArray.length;
	
    groups = groups;

    loaded = true;
}
*/

  var request = new XMLHttpRequest();
  request.open('GET', 'files/inf_ege.txt');

