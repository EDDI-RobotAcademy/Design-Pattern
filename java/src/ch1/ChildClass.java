package ch1;

public class ChildClass extends ParentClass {
    public ChildClass(int field) {
        super(field);
    }

    void printChild () {
        System.out.println("ChildClass: " + field);
    }
}
