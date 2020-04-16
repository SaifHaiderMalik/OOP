

// ES5


function Students(n,ag,add){

    this.name = n;
    this.age = ag;
    this.address = add;

    this.func = function(){

        console.log("running function");
    }
}


var rizwan = new Students("rizwan", 20, "address...");

console.log(rizwan.func());

var ameen = new Students("ameen", 25, "address....");

console.log(ameen.func());

var hamza = new Students("hamza", 30, "address...");

console.log(hamza.func());
