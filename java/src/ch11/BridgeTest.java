package ch11;

public class BridgeTest {
    public static void main(String[] args) {
        Display d1 = new Display(new StringDisplayImpl("Hello, EDDI."));
        Display d2 = new CountDisplay(new StringDisplayImpl("Hello, World."));
        CountDisplay d3 = new CountDisplay(new StringDisplayImpl("Hello, EDDI Robot Academy!"));
        d1.display();
        d2.display();
        d3.display();
        d3.multiDisplay(5);
    }
}
