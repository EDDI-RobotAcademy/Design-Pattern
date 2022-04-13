package ch5;

public class IntegerDisplay implements DisplayInterface {
    private Integer number;

    public IntegerDisplay(Integer number) {
        this.number = number;
    }

    @Override
    public void open() {
        System.out.println("숫자 시작!");
    }

    @Override
    public void print() {
        System.out.println("|" + number + "|");
    }

    @Override
    public void close() {
        System.out.println("숫자 끝!");
    }
}
