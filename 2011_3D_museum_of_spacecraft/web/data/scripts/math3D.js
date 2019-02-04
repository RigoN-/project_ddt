var Math;

function matrix4_frustum(left, right, bottom, top, near, far)
{
    var X = 2*near/(right-left);
    var Y = 2*near/(top-bottom);
    var A = (right+left)/(right-left);
    var B = (top+bottom)/(top-bottom);
    var C = -(far+near)/(far-near);
    var D = -2*far*near/(far-near);

    return [[X, 0, A, 0],
            [0, Y, B, 0],
            [0, 0, C, D],
           [0, 0, -1, 0]];
};

function matrix4_perspective(angle, aspect, near, far)
{
  var f = Math.tan(0.5 * (Math.PI - angle));
  var range = near - far;
  var a = near * Math.tan(angle * Math.PI / 360.0);
  var b = -a;
  var c = b * aspect;
  var d = a * aspect;
  return matrix4_frustum(c,d,b,a,near,far);
};

function matrix4_orthographic(left, right, bottom, top, near, far)
{
  return [
    [2 / (right - left), 0, 0, 0],
    [0, 2 / (top - bottom), 0, 0],
    [0, 0, 1 / (near - far), 0],
    [(left + right) / (left - right),
     (bottom + top) / (bottom - top),
     near / (near - far), 1]
  ];
};



function mulMatrixMatrix4(a, b)
{
  var a0 = a[0];
  var a1 = a[1];
  var a2 = a[2];
  var a3 = a[3];
  var b0 = b[0];
  var b1 = b[1];
  var b2 = b[2];
  var b3 = b[3];
  var a00 = a0[0];
  var a01 = a0[1];
  var a02 = a0[2];
  var a03 = a0[3];
  var a10 = a1[0];
  var a11 = a1[1];
  var a12 = a1[2];
  var a13 = a1[3];
  var a20 = a2[0];
  var a21 = a2[1];
  var a22 = a2[2];
  var a23 = a2[3];
  var a30 = a3[0];
  var a31 = a3[1];
  var a32 = a3[2];
  var a33 = a3[3];
  var b00 = b0[0];
  var b01 = b0[1];
  var b02 = b0[2];
  var b03 = b0[3];
  var b10 = b1[0];
  var b11 = b1[1];
  var b12 = b1[2];
  var b13 = b1[3];
  var b20 = b2[0];
  var b21 = b2[1];
  var b22 = b2[2];
  var b23 = b2[3];
  var b30 = b3[0];
  var b31 = b3[1];
  var b32 = b3[2];
  var b33 = b3[3];
  return [[a00 * b00 + a10 * b01 + a20 * b02 + a30 * b03,
           a01 * b00 + a11 * b01 + a21 * b02 + a31 * b03,
           a02 * b00 + a12 * b01 + a22 * b02 + a32 * b03,
           a03 * b00 + a13 * b01 + a23 * b02 + a33 * b03],
          [a00 * b10 + a10 * b11 + a20 * b12 + a30 * b13,
           a01 * b10 + a11 * b11 + a21 * b12 + a31 * b13,
           a02 * b10 + a12 * b11 + a22 * b12 + a32 * b13,
           a03 * b10 + a13 * b11 + a23 * b12 + a33 * b13],
          [a00 * b20 + a10 * b21 + a20 * b22 + a30 * b23,
           a01 * b20 + a11 * b21 + a21 * b22 + a31 * b23,
           a02 * b20 + a12 * b21 + a22 * b22 + a32 * b23,
           a03 * b20 + a13 * b21 + a23 * b22 + a33 * b23],
          [a00 * b30 + a10 * b31 + a20 * b32 + a30 * b33,
           a01 * b30 + a11 * b31 + a21 * b32 + a31 * b33,
           a02 * b30 + a12 * b31 + a22 * b32 + a32 * b33,
           a03 * b30 + a13 * b31 + a23 * b32 + a33 * b33]];
};


function matrix4_identity()
{
  return [
    [1, 0, 0, 0],
    [0, 1, 0, 0],
    [0, 0, 1, 0],
    [0, 0, 0, 1]
  ];
};

function matrix4_translation(v)
{
  return [
    [1, 0, 0, v[0]],
    [0, 1, 0, v[1]],
    [0, 0, 1, v[2]],
    [0, 0, 0, 1]
  ];
};

function matrix4_setTranslation(a, v)
{
  a[3].splice(0, 4, v[0], v[1], v[2], 1);
  return a;
};

function getMatrixElements(m)
{
  var r = [];
  var mLength = m.length;
  alert(m.length);
  var k = 0;
  for (var i = 0; i < mLength; i++)
{
    for (var j = 0; j < m[i].length; j++)
{
      r[k++] = m[i][j];
    }
  }
  return r;
};

function flatten(m)
{
    return [m[0][0],m[1][0],m[2][0],m[3][0],
			m[0][1],m[1][1],m[2][1],m[3][1],
			m[0][2],m[1][2],m[2][2],m[3][2],
			m[0][3],m[1][3],m[2][3],m[3][3]];
}

function matrix4_Rotation(angle, axis)
{
  var x = axis[0];
  var y = axis[1];
  var z = axis[2];
  var n = Math.sqrt(x * x + y * y + z * z);
  x /= n;
  y /= n;
  z /= n;
  var xx = x * x;
  var yy = y * y;
  var zz = z * z;
  var c = Math.cos(angle);
  var s = Math.sin(angle);
  var oneMinusCosine = 1 - c;

  return [
    [xx + (1 - xx) * c,
     x * y * oneMinusCosine + z * s,
     x * z * oneMinusCosine - y * s,
     0],
    [x * y * oneMinusCosine - z * s,
     yy + (1 - yy) * c,
     y * z * oneMinusCosine + x * s,
     0],
    [x * z * oneMinusCosine + y * s,
     y * z * oneMinusCosine - x * s,
     zz + (1 - zz) * c,
     0],
    [0, 0, 0, 1]
  ];
};

  function degToRad(degs)
	{
	return (degs * Math.PI / 180.0);
	}
	
function inverse(m)
{
  var tmp_0 = m[2][2] * m[3][3];
  var tmp_1 = m[3][2] * m[2][3];
  var tmp_2 = m[1][2] * m[3][3];
  var tmp_3 = m[3][2] * m[1][3];
  var tmp_4 = m[1][2] * m[2][3];
  var tmp_5 = m[2][2] * m[1][3];
  var tmp_6 = m[0][2] * m[3][3];
  var tmp_7 = m[3][2] * m[0][3];
  var tmp_8 = m[0][2] * m[2][3];
  var tmp_9 = m[2][2] * m[0][3];
  var tmp_10 = m[0][2] * m[1][3];
  var tmp_11 = m[1][2] * m[0][3];
  var tmp_12 = m[2][0] * m[3][1];
  var tmp_13 = m[3][0] * m[2][1];
  var tmp_14 = m[1][0] * m[3][1];
  var tmp_15 = m[3][0] * m[1][1];
  var tmp_16 = m[1][0] * m[2][1];
  var tmp_17 = m[2][0] * m[1][1];
  var tmp_18 = m[0][0] * m[3][1];
  var tmp_19 = m[3][0] * m[0][1];
  var tmp_20 = m[0][0] * m[2][1];
  var tmp_21 = m[2][0] * m[0][1];
  var tmp_22 = m[0][0] * m[1][1];
  var tmp_23 = m[1][0] * m[0][1];

  var t0 = (tmp_0 * m[1][1] + tmp_3 * m[2][1] + tmp_4 * m[3][1]) -
      (tmp_1 * m[1][1] + tmp_2 * m[2][1] + tmp_5 * m[3][1]);
  var t1 = (tmp_1 * m[0][1] + tmp_6 * m[2][1] + tmp_9 * m[3][1]) -
      (tmp_0 * m[0][1] + tmp_7 * m[2][1] + tmp_8 * m[3][1]);
  var t2 = (tmp_2 * m[0][1] + tmp_7 * m[1][1] + tmp_10 * m[3][1]) -
      (tmp_3 * m[0][1] + tmp_6 * m[1][1] + tmp_11 * m[3][1]);
  var t3 = (tmp_5 * m[0][1] + tmp_8 * m[1][1] + tmp_11 * m[2][1]) -
      (tmp_4 * m[0][1] + tmp_9 * m[1][1] + tmp_10 * m[2][1]);

  var d = 1.0 / (m[0][0] * t0 + m[1][0] * t1 + m[2][0] * t2 + m[3][0] * t3);

  var row0 = [d * t0, d * t1, d * t2, d * t3];
  var row1 = [d * ((tmp_1 * m[1][0] + tmp_2 * m[2][0] + tmp_5 * m[3][0]) -
          (tmp_0 * m[1][0] + tmp_3 * m[2][0] + tmp_4 * m[3][0])),
       d * ((tmp_0 * m[0][0] + tmp_7 * m[2][0] + tmp_8 * m[3][0]) -
          (tmp_1 * m[0][0] + tmp_6 * m[2][0] + tmp_9 * m[3][0])),
       d * ((tmp_3 * m[0][0] + tmp_6 * m[1][0] + tmp_11 * m[3][0]) -
          (tmp_2 * m[0][0] + tmp_7 * m[1][0] + tmp_10 * m[3][0])),
       d * ((tmp_4 * m[0][0] + tmp_9 * m[1][0] + tmp_10 * m[2][0]) -
          (tmp_5 * m[0][0] + tmp_8 * m[1][0] + tmp_11 * m[2][0]))];
  var row2 =[d * ((tmp_12 * m[1][3] + tmp_15 * m[2][3] + tmp_16 * m[3][3]) -
          (tmp_13 * m[1][3] + tmp_14 * m[2][3] + tmp_17 * m[3][3])),
       d * ((tmp_13 * m[0][3] + tmp_18 * m[2][3] + tmp_21 * m[3][3]) -
          (tmp_12 * m[0][3] + tmp_19 * m[2][3] + tmp_20 * m[3][3])),
       d * ((tmp_14 * m[0][3] + tmp_19 * m[1][3] + tmp_22 * m[3][3]) -
          (tmp_15 * m[0][3] + tmp_18 * m[1][3] + tmp_23 * m[3][3])),
       d * ((tmp_17 * m[0][3] + tmp_20 * m[1][3] + tmp_23 * m[2][3]) -
          (tmp_16 * m[0][3] + tmp_21 * m[1][3] + tmp_22 * m[2][3]))];
  var row3 = [d * ((tmp_14 * m[2][2] + tmp_17 * m[3][2] + tmp_13 * m[1][2]) -
          (tmp_16 * m[3][2] + tmp_12 * m[1][2] + tmp_15 * m[2][2])),
       d * ((tmp_20 * m[3][2] + tmp_12 * m[0][2] + tmp_19 * m[2][2]) -
          (tmp_18 * m[2][2] + tmp_21 * m[3][2] + tmp_13 * m[0][2])),
       d * ((tmp_18 * m[1][2] + tmp_23 * m[3][2] + tmp_15 * m[0][2]) -
          (tmp_22 * m[3][2] + tmp_14 * m[0][2] + tmp_19 * m[1][2])),
       d * ((tmp_22 * m[2][2] + tmp_16 * m[0][2] + tmp_21 * m[1][2]) -
          (tmp_20 * m[1][2] + tmp_23 * m[2][2] + tmp_17 * m[0][2]))];
  return [row0, row1, row2, row3];
};

function transpose(m)
{
  var r = [];
  var m0Length = m[0].length;
  var mLength = m.length;
  for (var j = 0; j < m0Length; ++j)
{
    r[j] = [];
    for (var i = 0; i < mLength; ++i)
      r[j][i] = m[i][j];
  }
  return r;
};