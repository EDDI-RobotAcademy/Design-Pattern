package ch3;

import java.util.Iterator;

public class DataIteratorTest {
    public static void main(String[] args) {
        DataCollection dataCollection = new DataCollection(4);
        dataCollection.appendData(new Data("가즈아!"));
        dataCollection.appendData(new Data("간드아!"));
        dataCollection.appendData(new Data("고고싱!"));
        dataCollection.appendData(new Data("레추고!"));

        Iterator<Data> it = dataCollection.iterator();
        while (it.hasNext()) {
            Data book = it.next();
            System.out.println(book.getName());
        }
        System.out.println();

        for (Data book: dataCollection) {
            System.out.println(book.getName());
        }
        System.out.println();
    }
}
