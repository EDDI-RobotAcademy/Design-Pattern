package ch23;

public class Printer implements Printable {
    private String name;

    public Printer() {
        heavyJob("Printer 객체 생성중");
    }

    public Printer(String name) {
        this.name = name;
        heavyJob("Printer 객체(" + name + ") 생성중");
    }

    @Override
    public void setPrinterName(String name) {
        this.name = name;
    }

    @Override
    public String getPrinterName() {
        return name;
    }

    @Override
    public void print(String string) {
        System.out.println("=== " + name + " ===");
        System.out.println(string);
    }

    private void heavyJob(String msg) {
        System.out.print(msg);
        for (int i = 0; i < 5; i++) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
            }
            System.out.print(".");
        }
        System.out.println("완료!");
    }
}
