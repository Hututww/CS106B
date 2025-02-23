#include <iostream>
#include <string>
using namespace std;

//你好，我是注释

/*
雷猴，我也是注释，CS106B正式启动！
Gonna be the king of c++!
*/

//Function
    /*

    格式：
    returnType functionName(varType parameter1,varType parameter2){
    //code
    return variable;
    }

    */

void sayHello() {
    cout << "Hello, cfy!" << endl;
}

int add(int a =1, int b =2) {
    return a + b;
}




int main() {
	cout << "Hello, World!" << endl;//endl is 换行符
	
//now is time for Variables and Types，变量和类型
    
    /*命名变量的时候，在py里面下划线分开，在c++里面用camelCase：
    eg，在py里面有：cfy_cool = 1
    在c++ 里面就是：
    */
    int cfyCool = 1;
    //其中int叫Types,整数
    double cfyGpa = 3.73;//小数浮点数，也可以写成float
    string cfyName = "Steve";//字符串
    char cfySentence = 'a';//字符
    if (cfyCool == 1){
        cout << cfyName << " is " << cfySentence << " cool guy!" <<endl;
        cout << "My GPA is: " << cfyGpa << endl;
    }    
    cout << "The sum of 1 and 2 is: " << add() << endl;//default value
    cout << "The sum of 3 and 4 is: " << add(3,4) << endl;//defined value
    return 0;
}


//Control Flow
    /*
    a||b    逻辑或 return true if a or b is true 
    eg：0||1 = 1

    a&&b    逻辑与 return true if a and b is true
    eg：0&&1 = 0

    */

//Conditional Statements
    /*
    if(condition1){
        //code
    }
    
    else if(condition2){
        //code
    }
    
    else{
        //code
    }

    */

//Loops
    /*
    while(condition){
        //code
    }
    eg:
    int i = 0;
    while(i < 5){
        cout << i << " ";
        i++;
    }
    result: 0 1 2 3 4

    for(int i = 0; i < 5; i++){
        //code
    }
    eg:
    for(int i = 0; i < 6; i++){
        cout << i << " ";
    }
    result: 0 1 2 3 4 5

    */