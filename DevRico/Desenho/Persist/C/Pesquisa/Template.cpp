  template <class T>
  class List
  {
    T *v;
    int size;

  public:
    List(int);
    T& operator[](int i) {return v[i];}
  };

  // Out-of-class definitions require a special syntax:

  template <class T> List<T>::List(int n)
  {
    v = new T[n];
    size = n;
  }

Given the preceding class definitions, you can instantiate a list of any
type:

  List<int> x(20);
  List<Myclass> y(30);
  x[3] = 7;
  y[3] = m;               // m is type Myclass
