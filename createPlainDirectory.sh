echo "Enter directory name"
read name

if [ ! -d "$name" ]
then
    echo "Directory doesn't exit. Creating now"
    sleep 1
    mkdir ./$name
    echo -e "Directory created\n"
    sleep 1

    echo "C++ or Python?"
    read lang

    if [ "$lang" == "c++" ] || [ "$lang" == "C++" ]
    then
        echo "Creating main.cpp Timer-Chrono-milliseconds Template"
        touch $name/main.cpp
	    echo -e "#include <iostream>\n#include <chrono>\n#include <ctime>\n" >> $name/main.cpp
	    echo -e "using namespace std;\n" >> $name/main.cpp
        echo -e "int main(int argc, const char**argv)  {\n" >> $name/main.cpp
	    echo -e "    typedef chrono::high_resolution_clock Clock;" >> $name/main.cpp
        echo -e "    auto t1 = Clock::now();\n\n\n" >> $name/main.cpp
        echo -e "    auto t2 = Clock::now();" >> $name/main.cpp
        echo -e "    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);" >> $name/main.cpp
        echo -e "    cout << ns.count() << \" milliseconds\" << endl;" >> $name/main.cpp
        echo -e "    return 0;" >> $name/main.cpp
	    echo -e "}" >> $name/main.cpp
        echo "Created main.cpp in new directory"
    elif [ "$lang" == "Python" ] || [ "$lang" == "C++" ]
    then
        echo "Creating main.py with Timer Template"
        touch $name/main.py
        echo -e "import time\n" >> $name/main.py
        echo -e "start = time.time()\n\n\n\n" >> $name/main.py
        echo -e "elapsed = time.time()\n" >> $name/main.py
        echo -e "print(\"found in %s seconds\") % (elapsed)" >> $name/main.py
        echo "Created main.py in new directory"
    else
        echo "Error Please check spelling of C++ or Python"
        rm -rf ./$name
    fi
else
    echo "Error - File exits"
fi
