package ch5;

public class DisplayTest {
    public static void main(String[] args) {
        DisplayInterface d1 = new CharDisplay('H');
        DisplayInterface d2 = new IntegerDisplay(777);

        d1.display();
        d2.display();
    }
}
