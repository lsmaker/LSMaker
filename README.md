# LSMaker
This is the source code of the basic LSMaker Arduino software.

## Download
[LSMaker.zip](https://github.com/lsmaker/lsmaker/releases/download/1.0/LSMaker.zip)

## Clone

**Using SSH**
```
git clone --recursive git@github.com:lsmaker/LSMaker.git LSMaker
```

**Using HTTPS**
```
git clone --recursive https://github.com/lsmaker/LSMaker.git LSMaker
```

## Methods

- `void init(void)`:

**Description**: This procedure performs the basic initializations needed by the LSMaker Arduino platform. It is important that this method is **ALWAYS** called at the very beginning of your project's `void setup()` procedure.

- `bool addModule(LSMakerModule *module, unsigned long period = 0)`: 

**Description**: This method subscribes the LSMakerModule instance received to the LSMaker system scheduler. If no period value is provided the LSMaker scheduler will call the module's *execute()* module as soon as possible (62.5us). Otherwise, if period value is provided (in microseconds), the LSMaker scheduler will call the *execute()* method when the elapsed time since the last call to the module's *execute()* method is bigger or equals than the period value.

**Return value**: True is returned if the module has been successfully subscribed to the LSMaker scheduler. Otherwise, false is returned.

- `bool removeModule(LSMakerModule *module)`:

**Description**: This method checks if the LSMakerModule instance received is currently attached to LSMaker scheduler. If so, the instance is removed. Otherwise, no operation is performed.

**Return value**: True is returned if the moudle has been successfully removed from the LSMaker scheduler. Otherwise, false is returned.

## Classes

- `LinkedList<T>`: This class implements a generic list that can hold any kind of data on its nodes.
```
template <class T> class LinkedList{

  public:

    //Constructors & Destructors
    LinkedList(void);

    //Add, Get & Remove interface
    void addElement(T element);
    T getElement(void);
    bool removeElement(void);

    //Iteration interface
    void moveFirst(void);
    void moveNext(void);
    bool hasNext(void);

};

```

## Author
[Albert Lloveras](https://github.com/alloveras)

## License
The MIT License (MIT)
Copyright &copy; 2016 La Salle, Universitat Ramón Llull

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

