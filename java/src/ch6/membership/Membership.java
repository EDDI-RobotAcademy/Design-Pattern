package ch6.membership;

import ch6.framework.Product;

public class Membership extends Product {
    private String owner;

    Membership(String owner) {
        System.out.println(owner + " 멤버쉽 생성");
        this.owner = owner;
    }

    @Override
    public void use() {
        System.out.println(this + " 사용");
    }

    @Override
    public String toString() {
        return "[Membership:" + owner + "]";
    }

    public String getOwner() {
        return owner;
    }
}
