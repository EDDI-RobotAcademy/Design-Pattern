package ch3;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class DataCollectionIterator implements Iterator<Data> {
    private DataCollection dataCollection;
    private int index;

    public DataCollectionIterator(DataCollection bookShelf) {
        this.dataCollection = bookShelf;
        this.index = 0;
    }

    @Override
    public boolean hasNext() {
        if (index < dataCollection.getLength()) {
            return true;
        } else {
            return false;
        }
    }

    @Override
    public Data next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        Data book = dataCollection.getBookAt(index);
        index++;
        return book;
    }
}
