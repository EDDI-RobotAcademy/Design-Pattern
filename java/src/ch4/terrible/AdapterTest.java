package ch4.terrible;

import ch4.Banner;

public class AdapterTest {
    public static void main(String[] args) {
        Banner ban = new Banner("Hello");
        ban.showWithParen();
        ban.showWithAster();
    }
}
