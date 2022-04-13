package ch6.membership;

import ch6.framework.Factory;
import ch6.framework.Product;

public class MembershipFactory extends Factory {
    @Override
    protected Product createProduct(String owner) {
        return new Membership(owner);
    }

    @Override
    protected void registerProduct(Product product) {
        System.out.println(product + " 등록");
    }
}
