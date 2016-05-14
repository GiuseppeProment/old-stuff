import HelloApp.*;

import org.omg.CosNaming.*;
import org.omg.CosNaming.NamingContextPackage.*;
import org.omg.CORBA.*;

/*
class HelloServant extends _HelloImplBase 
{
    public String sayHello()
    {
	return "\nHello world !!\n";
    }
}
*/
class HelloServant extends _HelloStub
{
    public String sayHello()
    {
			return "\nHello world !!\n";
    }
}

public class HelloServer {

    public static void main(String args[])
    {
	try{
	    // create and initialize the ORB
	    ORB orb = ORB.init(args, null);

	    // create servant and register it with the ORB
	    HelloServant helloRef = new HelloServant();
	    orb.connect(helloRef);

	    // get the root naming context
	    org.omg.CORBA.Object objRef = 
		orb.resolve_initial_references("NameService");
	    NamingContext ncRef = NamingContextHelper.narrow(objRef);

	    // bind the Object Reference in Naming
	    NameComponent nc = new NameComponent("Hello", "");
	    NameComponent path[] = {nc};
	    ncRef.rebind(path, helloRef);

	    // wait for invocations from clients
            java.lang.Object sync = new java.lang.Object();
            synchronized (sync) {
                sync.wait();
            }

	} catch (Exception e) {
	    System.err.println("ERROR: " + e);
	    e.printStackTrace(System.out);
	}
    }
}