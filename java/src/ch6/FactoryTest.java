package ch6;

import ch6.framework.Factory;
import ch6.framework.Product;
import ch6.membership.MembershipFactory;

public class FactoryTest {
    public static void main(String[] args) {
        Factory factory = new MembershipFactory();
        Product card1 = factory.create("짐 레이너");
        Product card2 = factory.create("타이커스");
        Product card3 = factory.create("제라툴");
        card1.use();
        card2.use();
        card3.use();
    }
}
