package ch2;

public class ParentClass {
    int field;
    //int field2;

    /*
    public ParentClass (int field, int field2) {
        this.field = field;
        this.field2 = field2;
    } */

    public ParentClass (int field) {
        this.field = field;
    }

    void controlField () {
        System.out.println("ParentClass: " + field);
    }
}
