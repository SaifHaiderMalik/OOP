
class Students {

    constructor(n,ag, add){

        this.name = n
        this.age = ag
        this.address = add

    }

    func(){

        console.log("func running "+ this.name)


    }

    func2(){

        console.log("func running "+ this.name)
        
    }


    static dumval = "ABC"
}

console.log(Students.dumval)


var ameen = new Students ("ameen", 20, "address..")
console.log(ameen.func())

var rizwan = new Students("rizwan", 19, "address..")
console.log(rizwan.func())
