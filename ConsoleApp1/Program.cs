using System.Runtime.InteropServices;

namespace FakeDLL.ConsoleApp1
{
    internal class Startup
    {
        [DllImport("FakeDLL.dll")]
        public static extern IntPtr Create(int x);

        [DllImport("FakeDLL.dll")]
        public static extern int AddValue(IntPtr obj, int y);

        [DllImport("FakeDLL.dll", CharSet = CharSet.Unicode)]
        public static extern int HandleStringA(string inputStr, ref string outputStr);

        [DllImport("FakeDLL.dll", CharSet = CharSet.Unicode)]
        public static extern int HandleStringB(string inputStr, ref string outputStr);

        [DllImport("FakeDLL.dll", CharSet = CharSet.Unicode)]
        public static extern string HandleStringC(string inputStr);

        static void Main()
        {
            Console.WriteLine("Testing add...");

            IntPtr obj = Create(5);

            int result = AddValue(obj, 10);

            Console.WriteLine($"Result is {result}");

            string output = "uninitialised";

            result = HandleStringA("this was input", ref output);

            Console.WriteLine($"HandleStringA result is {result}, output is {output}");
                        
            output = "uninitialised";

            result = HandleStringB("this was input", ref output);

            Console.WriteLine($"HandleStringB result is {result}, output is {output}");

            string strRes = HandleStringC("this was input");

            Console.WriteLine($"HandleStringC result is {strRes}");
        }
    }
}



