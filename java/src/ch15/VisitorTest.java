package ch15;

public class VisitorTest {
    public static void main(String[] args) {
        System.out.println("Making root entries...");
        Directory rootdir = new Directory("root");
        Directory bindir = new Directory("bin");
        Directory tmpdir = new Directory("tmp");
        Directory usrdir = new Directory("usr");
        rootdir.add(bindir);
        rootdir.add(tmpdir);
        rootdir.add(usrdir);
        bindir.add(new File("vi", 10000));
        bindir.add(new File("latex", 20000));
        rootdir.accept(new ListVisitor());
        System.out.println();

        System.out.println("Making user entries...");
        Directory eddi = new Directory("eddi");
        Directory test = new Directory("test");
        Directory sdr = new Directory("sdr");
        usrdir.add(eddi);
        usrdir.add(test);
        usrdir.add(sdr);
        eddi.add(new File("diary.html", 100));
        eddi.add(new File("Composite.java", 200));
        test.add(new File("memo.tex", 300));
        sdr.add(new File("game.doc", 400));
        sdr.add(new File("junk.mail", 500));
        rootdir.accept(new ListVisitor());
    }
}
