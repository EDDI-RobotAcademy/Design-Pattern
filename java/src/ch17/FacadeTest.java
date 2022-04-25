package ch17;

import ch17.pagemaker.PageMaker;

public class FacadeTest {
    public static void main(String[] args) {
        PageMaker.makeWelcomePage("test@example.com", "welcome.html");
    }
}
