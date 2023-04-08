import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Scanner;

public class Read {
    public String[] read(File input) throws FileNotFoundException {
        LinkedList<String> list = new LinkedList<String>();
        Scanner sc = new Scanner(input);
        while (sc.hasNextLine()){
            String line = sc.nextLine();
            list.add(line);
       }
        String[] arr = new String[list.size()];
        list.toArray(arr);
        return arr;
    }
}
