using System.Diagnostics;
using System.Runtime.InteropServices;

namespace _353503_ABDULOV_LAB4 { 
    public class Program{

        public static void CreateFolder() {
            string folderPath = "D:\\C#\\353503_ABDULOV_LAB4\\353503_ABDULOV_LAB4\\ABDULOV_Lab4";

            DirectoryInfo dirInfo = new DirectoryInfo(folderPath);
            if (Directory.Exists(folderPath)){
                foreach (FileInfo file in dirInfo.GetFiles())
                {
                    file.Delete();
                }
            }else{
                Directory.CreateDirectory(folderPath);
            }

            using (File.Create(folderPath + "\\" + Path.GetRandomFileName() + ".txt")) { }
            using (File.Create(folderPath + "\\" + Path.GetRandomFileName() + ".rtf")) { }
            using (File.Create(folderPath + "\\" + Path.GetRandomFileName() + ".dat")) { }
            using (File.Create(folderPath + "\\" + Path.GetRandomFileName() + ".inf")) { }

            foreach (FileInfo file in dirInfo.GetFiles()){
                Console.WriteLine("Файл (" + Path.GetFileNameWithoutExtension(folderPath + "\\" + file.Name) + ") имеет расширение " + file.Extension);
            }

            Console.WriteLine();
            Console.WriteLine();
        }
        public static void Main(string[] args) {
            FileService<string> fileService = new FileService<string>();
            string fileName = "File";
            CreateFolder();
            
            Tenant t1 = new Tenant("Sasha", 5, false);
            Tenant t2 = new Tenant("Milana", 5, false);
            Tenant t3 = new Tenant("Pelix", 3, true);
            Tenant t4 = new Tenant("zahar", 10, false);
            Tenant t5 = new Tenant("vlad", 4, true);
            Tenant t6 = new Tenant("aashaa", 5, false);
            Tenant t7 = new Tenant("Aaaa", 5, false);

            IEnumerable<Tenant> tenants = new List<Tenant>() { t1, t2, t3, t4, t5, t6, t7};

            fileService.SaveData(tenants, fileName);

            File.Create("D:\\C#\\353503_ABDULOV_LAB4\\353503_ABDULOV_LAB4\\File\\" + fileName + ".bin");

            //List<string> strings = (fileService.ReadFile(fileName).ToList());

            //foreach (string s in strings) {
            //    Console.WriteLine(s);
            //}

            //Console.WriteLine();
            //Console.WriteLine();


            //List<Tenant> list = new List<Tenant>();

            //string newFileName = "NewFile";

            
            //if (File.Exists("D:\\C#\\353503_ABDULOV_LAB4\\353503_ABDULOV_LAB4\\File\\" + newFileName + ".bin")){

            //    File.Delete("D:\\C#\\353503_ABDULOV_LAB4\\353503_ABDULOV_LAB4\\File\\" + newFileName + ".bin");
            //}

            //File.Move("D:\\C#\\353503_ABDULOV_LAB4\\353503_ABDULOV_LAB4\\File\\" + fileName + ".bin",
            //    "D:\\C#\\353503_ABDULOV_LAB4\\353503_ABDULOV_LAB4\\File\\" + newFileName + ".bin");

            //strings = (fileService.ReadFile(newFileName).ToList());

            //foreach (string s in strings){
            //    Tenant tenant = Tenant.ToTenantFromString(s);
            //    list.Add(tenant);
            //}

            //Console.WriteLine();

            //List<Tenant> sortedListByName = list.OrderBy(t => t, new Comparer<Tenant>()).ToList();

            //foreach (var tenant in sortedListByName){
            //    Console.WriteLine(tenant.GetName());
            //}

            //Console.WriteLine();
            //Console.WriteLine("RENT:");

            //List<Tenant> sortedByRent = list.OrderByDescending(t => t.GetIsApartmentForRent()).ToList();
            //foreach (var a in sortedByRent){
            //    Console.WriteLine(a.ToString());
            //}

            //Console.WriteLine();
            //Console.WriteLine("FLOOR:");


            //List<Tenant> sortedByFloor = list.OrderByDescending(t => t.GetFloor()).ToList();
            //foreach (var a in sortedByFloor){
            //    Console.WriteLine(a.ToString());
            //}

        }

    }


}