//package PackTeste;

import javax.swing.*;
import java.awt.*;

public class Tela extends JFrame  {

public Tela() {
	super();
	initialize();
}

public Tela(String title) {
	super(title);
	initialize();
}


private void handleException(Throwable exception) {

	/* Uncomment the following lines to print uncaught exceptions to stdout */
	// System.out.println("--------- UNCAUGHT EXCEPTION ---------");
	// exception.printStackTrace(System.out);
}


private void initialize() {
   setDefaultCloseOperation(WindowConstants.DO_NOTHING_ON_CLOSE);
	setName("Alo");
   //getContentPane().setLayout(null);
   setSize(426, 240);
   try {
   Class.forName("javax.swing.JOptionPane");
   } catch (java.lang.Exception ex) {
     System.out.println ("\n*** Exception capturada ***\n");
   }
}

public static void main(java.lang.String[] args) {
  Tela Eu = new Tela("Tela de Entrada");
	AdaptadorWindow Adaptador = new AdaptadorWindow();
  Eu.addWindowListener(Adaptador);
	Eu.setVisible(true);
}


}





class AdaptadorWindow extends java.awt.event.WindowAdapter  {

public void windowClosing(java.awt.event.WindowEvent e) {
      if (JOptionPane.showConfirmDialog( (Frame) e.getSource(),"Fechar Janela ?","Selecione a opcao",JOptionPane.YES_NO_OPTION)==JOptionPane.YES_OPTION)
      {
         ( (Frame) e.getSource() ).dispose();
         System.exit(0);
      }
}

}