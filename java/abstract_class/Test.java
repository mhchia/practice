
abstract class AbstractShape {
    String name;
//    void draw(); // error: missing method body, or declare abstract
    abstract void draw();
    public void test() { // default method body
        System.out.println("test");
    }
}

interface IShape {
//    void draw() {} // error: interface abstract methods cannot have body
    void draw();
}


class Circle extends AbstractShape {
    public void draw() { // this method must be implemented.
        System.out.println("draw circle");
    }
    /*
    public void test() { // we can choose to override this method or not
        System.out.println("circle test");
    }
    */
}

public class Test {
    public static void main(String[] args) {
        Test t = new Test();
        t.testAbstract();
    }

    public void testAbstract() {
        Circle circle = new Circle();
        circle.draw(); circle.test();
    }
}
