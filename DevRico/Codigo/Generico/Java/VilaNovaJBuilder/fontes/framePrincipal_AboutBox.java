
//Title:      Sistema Administrativo Simples
//Version:    
//Copyright:  Copyright (c) 1998
//Author:     Giuseppe
//Company:    Abstract 
//Description:primeiro sistema real feito em java e
//jBuilder
import java.awt.*;
import java.awt.event.*;
import com.sun.java.swing.*;
import borland.jbcl.control.BevelPanel;
import borland.jbcl.control.ImageControl;

public class framePrincipal_AboutBox extends Dialog implements ActionListener{

  BevelPanel panel1 = new BevelPanel();
  BevelPanel panel2 = new BevelPanel();
  BevelPanel insetsPanel1 = new BevelPanel();
  BevelPanel insetsPanel2 = new BevelPanel();
  BevelPanel insetsPanel3 = new BevelPanel();
  JButton button1 = new JButton();
  ImageControl imageControl1 = new ImageControl();
  JLabel label1 = new JLabel();
  JLabel label2 = new JLabel();
  JLabel label3 = new JLabel();
  JLabel label4 = new JLabel();
  BorderLayout borderLayout1 = new BorderLayout();
  BorderLayout borderLayout2 = new BorderLayout();
  FlowLayout flowLayout1 = new FlowLayout();
  FlowLayout flowLayout2 = new FlowLayout();
  GridLayout gridLayout1 = new GridLayout();
  String product = "Sistema Administrativo Simples";
  String version = "";
  String copyright = "Copyright (c) 1998";
  String comments = "primeiro sistema real feito em java e";
  
  public framePrincipal_AboutBox(Frame parent)
  {
    super(parent);
    enableEvents(AWTEvent.WINDOW_EVENT_MASK);
    try 
    {
      jbInit();
    }
    catch (Exception e)
    {
      e.printStackTrace();
    }
    pack();
  }

  private void jbInit() throws Exception 
  {
    this.setTitle("About");
    setResizable(false);
    panel1.setLayout(borderLayout1);
    panel2.setLayout(borderLayout2);
    insetsPanel1.setLayout(flowLayout1);
    insetsPanel1.setBevelInner(BevelPanel.FLAT);
    insetsPanel2.setLayout(flowLayout1);
    insetsPanel2.setMargins(new Insets(10, 10, 10, 10));
    insetsPanel2.setBevelInner(BevelPanel.FLAT);
    gridLayout1.setRows(4);
    gridLayout1.setColumns(1);
    label1.setText(product);
    label2.setText(version);
    label3.setText("Copyright (c) 2001");
    label4.setText(comments);
    insetsPanel3.setLayout(gridLayout1);
    insetsPanel3.setMargins(new Insets(10, 60, 10, 10));
    insetsPanel3.setBevelInner(BevelPanel.FLAT);
    button1.setText("OK");
    button1.addActionListener(this);
    insetsPanel2.add(imageControl1, null);
    panel2.add(insetsPanel2, BorderLayout.WEST);
    this.add(panel1, null);
    insetsPanel3.add(label2, null);
    insetsPanel3.add(label3, null);
    insetsPanel3.add(label4, null);
    panel2.add(insetsPanel3, BorderLayout.CENTER);
    insetsPanel3.add(label1, null);
    insetsPanel1.add(button1, null);
    panel1.add(insetsPanel1, BorderLayout.SOUTH);
    panel1.add(panel2, BorderLayout.NORTH);
  }

  protected void processWindowEvent(WindowEvent e)
  {
    if (e.getID() == WindowEvent.WINDOW_CLOSING)
    {
      cancel();
    }
    super.processWindowEvent(e);
  }

  void cancel()
  {
    dispose();
  }

  public void actionPerformed(ActionEvent e)
  {
    if (e.getSource() == button1)
    {
      cancel();
    }
  }
}
 
