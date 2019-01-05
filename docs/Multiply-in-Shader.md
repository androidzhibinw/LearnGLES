
## Shader 中的乘法

在GLSL Shader 中，经常会使用乘法 (*) 操作符， 不同类型的操作数在一起相乘的意义是有些不同的，下面来举例说明一下。

### Float, Vector, Matrix 乘法 

GLSL Shader 中， 常用的类型有基本类型(int/float) 以及向量(vector)和矩阵 (matrix)， 当它们使用乘法操作符进行运算时，计算方法是不同的。

例如有三个变量,分别是float，vecrot 和 matrix ：

    float myFloat(0.5);
    vec4  myVector(1,2,3,4);
    mat4  myMatrix(1,2,3,4,
                   5,6,7,8,
                   9,10,11,12,
                   13,14,15,16);

- float 和 float 相乘： 就是一般的两个数相乘

    float newFloat = myFloat * myFloat; // 0.5*0.5 = 0.25

- vector 和 float 相乘： vector 中每一个分量和 float 相乘，得到一个新的 vector

    vec4 newVector = myFloat * myVector; // (0.5\*1, 0.5\*2, 0.5\*4, 0.5\*4) = (0.5,1,1.5,2)

- vector vA 和 vector vB 相乘：vA 中的每一个分量和 vB 中的对应分量相乘， 得到一个新的 vector

  vec4 newVector = myVector * myVector; // (1\*1, 2\*2, 3\*3, 4\*4) = (1, 4, 9, 16)
  
- matrix 和 float 相乘： matrix 中每一个分量和 float 相乘， 得到一个新的 matrix 
    
    mat4 newMatrix = myMatrix * myFloat; //(1\*0.5,2\*0.5,3\*0.5,4\*0.5,5\*0.5,6\*0.5,7\*0.5,8\*0.5,9\*0.5,10\*0.5,11\*0.5,12\*0.5,13\*0.5,14\*0.5,15\*0.5,16\*0.5)=(0.5,1,1.5,2,2.5,3,3.5,4,4.5,5,5.5,6,6.5,7,7.5,8)
    
- matrix 和 vector 相乘： matrix 的行分量和 vector 相乘，得到一个新的 vector 

    vec4 newVector = myMatrix * myVector;
    
    //newVector[0] = myMatrix[0][0]* myVector[0] + myMatrix[0][1] * myVector[1] + myMatrix[0][2] * myVector[2] + myMatrix[0][3] * myVector[3] = 1\*1 + 2\*2 + 3\*3 + 4\*4 = 1 + 4 + 9 + 16 = 30
    
    //newVector[1] = 5\*1 + 6\*2 + 7 * 3 + 8 * 4 = 380
    
    //newVector[2] = 9 * 1 + 10 * 2 + 11 * 3 + 12 * 4 = 636
    
    //newVector[3] = 13 * 1 + 14 * 2 + 15 * 3 + 16 * 4 = 892
    
- matrix mA 和 matrix mB 相乘：mA 的行分量 和 mB 的列分量 相乘， 得到一个新的 matrix/vector/float 


### Vector 的内积(dot product) 和 外积(cross product) 

在数学上, 两个向量(Vector)相乘，有两种乘法，一种称为内积(dot product)， 另一种称为外积(cross product).

#### Vector 的内积 

两个向量的内积是一个数， 它的值为两个向量的模(长度)相乘,再乘以两个向量夹角的余弦值。

内积运算在 GLSL 中是通过内置函数 dot 来实现的。

    float dotP = dot(vA, vB); // dotP = vA[0] * vB[0] + vA[1] * vB[1] + vA[2] * vB[2] + vA[3] * vB[3] 

#### Vector 的外积 （三维） 

两个向量的外积是一个向量， 它的值为两个向量的模(长度)相乘,再乘以两个向量夹角的正弦值， 方向垂直两个向量的平面（并符合右手法则） 

外积运算在 GLSL 中是通过内置函数 cross  来实现的。

    vec3 vA, vB;
    vec3 crossP = cross(vA, vB); 
    //crossP[0] = vA[1] * vB[2] - vA[2] * vB[1]
    //crossP[1] = vA[2] * vB[0] - vA[0] - vB[2]
    //crossP[2] = vA[0] * vB[1] - vA[1] - vB[0] 

