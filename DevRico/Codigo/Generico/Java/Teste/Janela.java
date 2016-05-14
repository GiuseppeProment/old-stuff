
package Teste;

import java.net.URL;
import java.sql.*;
import java.applet.*;
import java.awt.*;






public class Janela extends java.applet.Applet
{

/**
 * main entrypoint - starts the part when it is run as an application
 * @param args java.lang.String[]
 */
public void init() {
	try {
		Tela aTela = new Tela();
		try {
			Class aCloserClass = Class.forName("uvm.abt.edit.WindowCloser");
			Class parmTypes[] = { java.awt.Window.class };
			Object parms[] = { aTela };
			java.lang.reflect.Constructor aCtor = aCloserClass.getConstructor(parmTypes);
			aCtor.newInstance(parms);
		} catch (java.lang.Throwable exc) {};
		aTela.setVisible(true);
	} catch (Throwable exception) {
		System.err.println("Exception occurred in main() of java.awt.Frame");
	}
}

};