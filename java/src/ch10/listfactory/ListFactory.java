package ch10.listfactory;

import ch10.factory.Factory;
import ch10.factory.Link;
import ch10.factory.Page;
import ch10.factory.Tray;

public class ListFactory extends Factory {
    @Override
    public Link createLink(String caption, String url) {
        return new ListLink(caption, url);
    }

    @Override
    public Tray createTray(String caption) {
        return new ListTray(caption);
    }

    @Override
    public Page createPage(String title, String author) {
        return new ListPage(title, author);
    }
}
