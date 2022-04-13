package ch2;

public class ChildClass extends ParentClass {

    /*
    public ChildClass(int field, int field2) {
        super(field, field2);
    } */

    public ChildClass(int field) {
        super(field);
    }

    void printChild () {
        System.out.println("ChildClass: " + field);
    }
}
