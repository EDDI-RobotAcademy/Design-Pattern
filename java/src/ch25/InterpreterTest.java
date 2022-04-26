package ch25;

import java.nio.file.Files;
import java.nio.file.Path;

public class InterpreterTest {
    public static void main(String[] args) {
        try {
            for (String text: Files.readAllLines(Path.of("src/ch25/program.txt"))) {
                System.out.println("text = \"" + text + "\"");
                Node node = new ProgramNode();
                node.parse(new Context(text));
                System.out.println("node = " + node);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
