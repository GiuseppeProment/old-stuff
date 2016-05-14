import java.awt.*;
import java.awt.event.*;

public class Imprime extends Frame implements ActionListener,WindowListener {

    public Imprime() {
        super("Teste de Impressao");

       {Button b = new Button("Imprime texto");
        b.setActionCommand("Imprime");
        b.addActionListener(this);
        add("South", b);  }

       {Button b = new Button("Beep");
        b.setActionCommand("Beep");
        b.addActionListener(this);
        add("North", b);  }

				// adiciona eu mesmo como ouvidor de eventos
				// pois estou implementado a interface WindowListener
				addWindowListener(this);

        pack();
    }

    public void actionPerformed(ActionEvent e) {
        String cmd = e.getActionCommand();
				Dimension papel;
        if (cmd.equals("Imprime")) {
            PrintJob pjob = getToolkit().getPrintJob(this,
                               "Teste de impressao", null);
            if (pjob != null) {
                Graphics pg = pjob.getGraphics();
                if (pg != null) {
									  //pg.drawString("Teste de impressao em java",100,100);
                    //pg.dispose(); // flush page
										papel = pjob.getPageDimension();
										System.out.println("---- tamanho do papel ----");
                    System.out.println("height=");
                    System.out.println(papel.height);
                    System.out.println("width=");
                    System.out.println(papel.width);
										System.out.println("--------------------------");
                 }
                pjob.end();
            }
        }
				if (cmd.equals("Beep") )
				{
					getToolkit().beep();
					//setVisible(false);
          //dispose();
				}
    }

	public void windowClosing(java.awt.event.WindowEvent e) {
 		dispose();
		System.exit(0);
	}

public void windowActivated(java.awt.event.WindowEvent e) {}
public void windowClosed(java.awt.event.WindowEvent e) {}
public void windowDeactivated(java.awt.event.WindowEvent e) {}
public void windowDeiconified(java.awt.event.WindowEvent e) {}
public void windowIconified(java.awt.event.WindowEvent e) {}
public void windowOpened(java.awt.event.WindowEvent e) {}


    public static void main(String args[]) {
        Imprime test = new Imprime();
        test.show();
    }
}