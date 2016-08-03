echo "Running deleteBinaryFiles.sh"

for d in *;
do
    (
    cd $d
    if [ ! -f "main.java" ]
    then
        touch main.java

        echo "Creating main.java Timer Template"
        echo -e "import java.lang.*;\n" >> main.java

        echo -e "public class main { " >> main.java
        echo -e "   public static void main(String[] args) { " >> main.java
        echo -e "       long startTime = System.currentTimeMillis();\n\n\n\n\n\n" >> main.java
        echo -e "       long endTime = System.currentTimeMillis();" >> main.java
        echo -e "       long totalSpan = System.currentTimeMillis();" >> main.java
        echo -e "       System.out.println(\"Completed in \" + totalSpan + \" milliseconds.\");" >> main.java
        echo -e "   }" >> main.java
        echo -e "}" >> main.java
    fi
    )
done
