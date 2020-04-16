
class Parent{

    constructor(age){

        this.age = age
        this.name = "Zeeshan";
        this.address = "Address...."

    }
}


var _parent = new Parent(50)
console.log(_parent)



class Child extends Parent{

    constructor(age){

        super(age)

    }

}


class Child2 extends Parent{

    
    constructor(age){

        super(age)

    }

}


var _child = new Child(15)
console.log(_child)


var _child2 = new Child2(20)
console.log(_child2)