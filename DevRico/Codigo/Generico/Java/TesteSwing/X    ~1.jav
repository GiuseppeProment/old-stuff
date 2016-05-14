import java.util.*;
//import java.text.DateFormat.*;
import java.text.*;

class T {

public static void main (String args[]) {

System.out.println("\nSaida via out");
System.err.println("\nSaida via err");

// Format the current time.
SimpleDateFormat formatter
    = new SimpleDateFormat ("dd/MM/yyyy");

Date data1 = new Date(); // data corrente
String dateString = formatter.format(data1);

// Parse the previous string back into a Date.
ParsePosition pos = new ParsePosition(0);
Date data2 = formatter.parse(dateString, pos);






  }
}