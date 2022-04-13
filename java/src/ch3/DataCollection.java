package ch3;

import java.util.Iterator;

public class DataCollection implements Iterable<Data> {
    private Data[] datas;
    private int last = 0;

    public DataCollection(int maxsize) {
        this.datas = new Data[maxsize];
    }

    public Data getBookAt(int index) {
        return datas[index];
    }

    public void appendData(Data data) {
        this.datas[last] = data;
        last++;
    }

    public int getLength() {
        return last;
    }

    @Override
    public Iterator<Data> iterator() {
        return new DataCollectionIterator(this);
    }
}
