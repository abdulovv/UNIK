using System.Collections.Generic;
using System.Reflection;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace _353503_ABDULOV_LAB6 {
    public class Program() {
        public static void Main(string[] args) {

            Employee employee1 = new Employee("Sasha", 18, true);
            Employee employee2 = new Employee("Milana", 19, true);
            Employee employee3 = new Employee("Zahar", 24, true);
            Employee employee4 = new Employee("Pelix", 11, false);

            IEnumerable<Employee> data = new List<Employee>(){ employee1,
                                                               employee2,
                                                               employee3,
                                                               employee4 };

            string fileName = "File";
            string assemblyPath = "D:\\C#\\ClassLibrary_LAB6\\bin\\Debug\\net8.0\\ClassLibrary_LAB6.dll";
            Assembly assembly = Assembly.LoadFrom(assemblyPath);

            Type? type = assembly.GetType("ClassLibrary_LAB6.FileService`1");
            Type genericType = type.MakeGenericType(typeof(Employee));
            object? instance = Activator.CreateInstance(genericType);
           
            MethodInfo? saveData = genericType.GetMethod("SaveData");
            MethodInfo? readFile = genericType.GetMethod("ReadFile");

            saveData?.Invoke(instance, new object[] { data, fileName });

            var employees = readFile.Invoke(instance, new object[] {fileName});

            foreach ( var empl in (List<Employee>)employees) {
                Console.WriteLine("Name:" + empl.Name + "\nAge:" + empl.age + "\nisKind:"+empl.isKind+"\n\n");
            }



        }
    }
}