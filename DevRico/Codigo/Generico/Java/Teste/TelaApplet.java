
package Teste;

import java.net.URL;
import java.sql.*;
import java.applet.*;
import java.awt.*;











/**
 * This class was generated by a SmartGuide.
 *
 */
class Tela extends java.awt.Frame implements java.awt.event.ActionListener, java.awt.event.WindowListener {
	private java.awt.Button ivjExecute = null;
	private java.awt.Label ivjLabel1 = null;
	private java.awt.Label ivjLabelURL = null;
	private java.awt.TextArea ivjTextAreaResult = null;
	private java.awt.TextField ivjTextFieldSelect = null;
	private java.awt.TextField ivjTextFieldURL = null;

/**
 * Constructor
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
public Tela() {
	super();
	initialize();
}

/**
 * Tela constructor comment.
 * @param title java.lang.String
 */
public Tela(String title) {
	super(title);
}
/**
 * Method to handle events for the ActionListener interface.
 * @param e java.awt.event.ActionEvent
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
public void actionPerformed(java.awt.event.ActionEvent e) {
	// user code begin {1}
	// user code end
	if ((e.getSource() == getExecute()) ) {
		conn1(e);
	}
	// user code begin {2}
	// user code end
}

/**
 * conn0:  (Tela.window.windowClosing(java.awt.event.WindowEvent) --> Tela.dispose())
 * @param arg1 java.awt.event.WindowEvent
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private void conn0(java.awt.event.WindowEvent arg1) {
	try {
		// user code begin {1}
		// user code end
		this.dispose();
		// user code begin {2}
		System.exit(0);
		// user code end
	} catch (java.lang.Throwable ivjExc) {
		// user code begin {3}
		// user code end
		handleException(ivjExc);
	}
}

/**
 * conn1:  (Execute.action.actionPerformed(java.awt.event.ActionEvent) --> Tela.selecionar())
 * @param arg1 java.awt.event.ActionEvent
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private void conn1(java.awt.event.ActionEvent arg1) {
	try {
		// user code begin {1}
		// user code end
		this.selecionar();
		// user code begin {2}
		// user code end
	} catch (java.lang.Throwable ivjExc) {
		// user code begin {3}
		// user code end
		handleException(ivjExc);
	}
}

/**
 * This method was created by a SmartGuide.
 * @param rs java.sql.ResultSet
 * @exception java.sql.SQLException The exception description.
 */
public synchronized void exibir(java.sql.ResultSet rs) throws SQLException {

	getTextAreaResult().setText("");
	int i;
	ResultSetMetaData rsmd = rs.getMetaData ();
	int numCols = rsmd.getColumnCount ();
	String Linha = "";
	for (i=1; i<=numCols; i++) {
		if (i > 1)  Linha += ",";
		Linha += rsmd.getColumnLabel(i);
	}
	getTextAreaResult().append( Linha + '\n' );
	
	Linha = "";
	boolean more = rs.next ();
	while (more) {
		for (i=1; i<=numCols; i++) {
			if (i > 1) Linha += ",";
			Linha += rs.getString(i);
		}
		getTextAreaResult().append( Linha + '\n' );
		more = rs.next ();
		Linha = "";
	}
	
	return;
}
/**
 * Return the Execute property value.
 * @return java.awt.Button
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private java.awt.Button getExecute() {
	if (ivjExecute == null) {
		try {
			ivjExecute = new java.awt.Button();
			ivjExecute.setName("Execute");
			ivjExecute.setBounds(334, 45, 65, 22);
			ivjExecute.setLabel("Execute");
			// user code begin {1}
			// user code end
		} catch (java.lang.Throwable ivjExc) {
			// user code begin {2}
			// user code end
			handleException(ivjExc);
		}
	};
	return ivjExecute;
}

/**
 * Return the Label1 property value.
 * @return java.awt.Label
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private java.awt.Label getLabel1() {
	if (ivjLabel1 == null) {
		try {
			ivjLabel1 = new java.awt.Label();
			ivjLabel1.setName("Label1");
			ivjLabel1.setText("Select");
			ivjLabel1.setBounds(12, 71, 40, 22);
			// user code begin {1}
 			// user code end
		} catch (java.lang.Throwable ivjExc) {
			// user code begin {2}
			// user code end
			handleException(ivjExc);
		}
	};
	return ivjLabel1;
}


/**
 * Return the LabelURL property value.
 * @return java.awt.Label
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private java.awt.Label getLabelURL() {
	if (ivjLabelURL == null) {
		try {
			ivjLabelURL = new java.awt.Label();
			ivjLabelURL.setName("LabelURL");
			ivjLabelURL.setFont(new java.awt.Font("dialog", 0, 12));
			ivjLabelURL.setText("URL");
			ivjLabelURL.setBounds(9, 46, 35, 22);
			// user code begin {1}
			// user code end
		} catch (java.lang.Throwable ivjExc) {
			// user code begin {2}
			// user code end
			handleException(ivjExc);
		}
	};
	return ivjLabelURL;
}

/**
 * Return the TextAreaResult property value.
 * @return java.awt.TextArea
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private java.awt.TextArea getTextAreaResult() {
	if (ivjTextAreaResult == null) {
		try {
			ivjTextAreaResult = new java.awt.TextArea();
			ivjTextAreaResult.setName("TextAreaResult");
			ivjTextAreaResult.setBounds(9, 124, 453, 203);
			// user code begin {1}
			// user code end
		} catch (java.lang.Throwable ivjExc) {
			// user code begin {2}
			// user code end
			handleException(ivjExc);
		}
	};
	return ivjTextAreaResult;
}

/**
 * Return the TextFieldSelect property value.
 * @return java.awt.TextField
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private java.awt.TextField getTextFieldSelect() {
	if (ivjTextFieldSelect == null) {
		try {
			ivjTextFieldSelect = new java.awt.TextField();
			ivjTextFieldSelect.setName("TextFieldSelect");
			ivjTextFieldSelect.setBounds(9, 96, 453, 21);
			// user code begin {1}
			// user code end
		} catch (java.lang.Throwable ivjExc) {
			// user code begin {2}
			// user code end
			handleException(ivjExc);
		}
	};
	return ivjTextFieldSelect;
}

/**
 * Return the TextFieldURL property value.
 * @return java.awt.TextField
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private java.awt.TextField getTextFieldURL() {
	if (ivjTextFieldURL == null) {
		try {
			ivjTextFieldURL = new java.awt.TextField();
			ivjTextFieldURL.setName("TextFieldURL");
			ivjTextFieldURL.setBounds(43, 45, 275, 22);
			// user code begin {1}
			ivjTextFieldURL.setText("jdbc:odbc:<DSN>");
			// user code end
		} catch (java.lang.Throwable ivjExc) {
			// user code begin {2}
			// user code end
			handleException(ivjExc);
		}
	};
	return ivjTextFieldURL;
}

/**
 * Called whenever the part throws an exception.
 * @param exception java.lang.Throwable
 */
private void handleException(Throwable exception) {

	/* Uncomment the following lines to print uncaught exceptions to stdout */
	// System.out.println("--------- UNCAUGHT EXCEPTION ---------");
	// exception.printStackTrace(System.out);
}

/**
 * Initializes connections
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private void initConnections() {
	// user code begin {1}
	// user code end
	this.addWindowListener(this);
	getExecute().addActionListener(this);
}

/**
 * Initialize class
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private void initialize() {
	// user code begin {1}
	// user code end
	setName("Tela");
	setLayout(null);
	setSize(473, 345);
	setTitle("Acesso a Dados em Java Giuseppe (c) 1999");
	add(getLabelURL(), getLabelURL().getName());
	add(getTextFieldURL(), getTextFieldURL().getName());
	add(getLabel1(), getLabel1().getName());
	add(getTextFieldSelect(), getTextFieldSelect().getName());
	add(getTextAreaResult(), getTextAreaResult().getName());
	add(getExecute(), getExecute().getName());
	initConnections();
	// user code begin {2}
	// user code end
}


/**
 * This method was created by a SmartGuide.
 */
public synchronized void selecionar ( ) {

	String url   = getTextFieldURL().getText();
	String query = getTextFieldSelect().getText();
	try {
		Class.forName ("sun.jdbc.odbc.JdbcOdbcDriver");
		//DriverManager.setLogStream(System.out);
		Connection con = DriverManager.getConnection (
			url, "GPROMENT", "quark");
		Statement stmt = con.createStatement ();
		ResultSet rs = stmt.executeQuery (query);
		exibir(rs);
		rs.close();
		stmt.close();
		con.close();
	}
	catch (SQLException ex) {
	System.out.println ("\n*** SQLException caught ***\n");
	while (ex != null) {
		System.out.println ("SQLState: " +
				ex.getSQLState ());
		System.out.println ("Message:  " + ex.getMessage ());
		System.out.println ("Vendor:   " +
				ex.getErrorCode ());
		ex = ex.getNextException ();
		System.out.println ("");
		}
	}
	catch (java.lang.Exception ex) {
		ex.printStackTrace ();
	}

	return;
}
/**
 * Method to handle events for the WindowListener interface.
 * @param e java.awt.event.WindowEvent
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
public void windowActivated(java.awt.event.WindowEvent e) {
	// user code begin {1}
	// user code end
	// user code begin {2}
	// user code end
}

/**
 * Method to handle events for the WindowListener interface.
 * @param e java.awt.event.WindowEvent
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
public void windowClosed(java.awt.event.WindowEvent e) {
	// user code begin {1}
	// user code end
	// user code begin {2}
	// user code end
}

/**
 * Method to handle events for the WindowListener interface.
 * @param e java.awt.event.WindowEvent
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
public void windowClosing(java.awt.event.WindowEvent e) {
	// user code begin {1}
	// user code end
	if ((e.getSource() == this) ) {
		conn0(e);
	}
	// user code begin {2}
	// user code end
}

/**
 * Method to handle events for the WindowListener interface.
 * @param e java.awt.event.WindowEvent
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
public void windowDeactivated(java.awt.event.WindowEvent e) {
	// user code begin {1}
	// user code end
	// user code begin {2}
	// user code end
}

/**
 * Method to handle events for the WindowListener interface.
 * @param e java.awt.event.WindowEvent
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
public void windowDeiconified(java.awt.event.WindowEvent e) {
	// user code begin {1}
	// user code end
	// user code begin {2}
	// user code end
}

/**
 * Method to handle events for the WindowListener interface.
 * @param e java.awt.event.WindowEvent
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
public void windowIconified(java.awt.event.WindowEvent e) {
	// user code begin {1}
	// user code end
	// user code begin {2}
	// user code end
}

/**
 * Method to handle events for the WindowListener interface.
 * @param e java.awt.event.WindowEvent
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
public void windowOpened(java.awt.event.WindowEvent e) {
	// user code begin {1}
	// user code end
	// user code begin {2}
	// user code end
}

}


