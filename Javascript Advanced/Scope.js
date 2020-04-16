
//Example 1

/*
var username = "Saif Haider";

function modifyusername (){

    username = "Ali Aslam";
}

function showUserName(){

    console.log(userName);
}

alert(username);

modifyusername();
showUserName();

 */

//Example 2 

/*
function createusername() {


    userName = "Saif Haider";


}

function modifyusername() {

    if(userName){


        userName = "Ali Aslam";

    }


};

function showUserName() {

    console.log(userName);  


}


createusername();
showUserName(); 
modifyusername();
showUserName(); 

*/

//Example 3

/*
function createUserName() {

    var userName = "Ameen Alam";
}
function showUserName() {

    console.log(userName);
}
createUserName();
showUserName(); // throws error: userName is not defined

*/


//Example 4

/*
var userName = "Ameen Alam";
function ShowUserName()
{
    var userName = "Daniyal Nagori";
    console.log(userName); // "Daniyal Nagori"
}
ShowUserName();
console.log(userName); // Ameen Alam

*/

//Example 5


/*
function NoBlockLevelScope(){
    
    if (1 > 0)
    {
        var myVar = 22;
    }
    console.log(myVar);
}

NoBlockLevelScope();

*/

//Example 6


/*
var age = 100;

function go(){
 var age = 200;
 var hair =  'black';
 console.log(age);
 console.log(hair);
}
go();
console.log(age);

*/

//Example 7


/*
if (true) {

    // userName is in the global scope because of the 'var' keyword
    var userName = 'Ameen Alam';

    console.log(userName); // output 'Ameen Alam'

    // age is in the local scope because of the 'let' keyword
    let age = 20;

    console.log(age); // output 20

    // skills is in the local scope because of the 'const' keyword
    const skills = 'JavaScript';

    console.log(skills); // output 'JavaScript'
 }

 console.log(userName); // output 'Ameen Alam'
 console.log(age); // Uncaught ReferenceError: age is not defined
 console.log(skills); // Uncaught ReferenceError: skills is not defined
 
 */