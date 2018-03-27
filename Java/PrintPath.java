/**
 * PrintPath
 * compile/run with javac 1.8.0_102
 */

import java.util.Arrays;
import java.util.List;

public class PrintPath {

    public static void main(String[] args) {

        String sysVarPath = System.getenv("PATH");
        String[] items = sysVarPath.split(";");
        List<String> itemList = Arrays.asList(items);

        System.out.println("");

        for (String var : itemList) {
            System.out.println(var);            
        }
        
    }

}
