using System.Runtime.InteropServices;
using System.Text;

namespace FakeDLL.ConsoleApp1
{
    internal class Startup
    {
        [DllImport("FakeDLL.dll")]
        public static extern IntPtr Create(int x);

        [DllImport("FakeDLL.dll")]
        public static extern int AddValue(IntPtr obj, int y);

        //[DllImport("FakeDLL.dll", CharSet = CharSet.Ansi)]
        //public static extern int HandleStringA(string inputStr, ref string outputStr);

        //[DllImport("FakeDLL.dll", CharSet = CharSet.Unicode)]
        //public static extern int HandleStringB(string inputStr, ref string outputStr);

        //[DllImport("FakeDLL.dll", CharSet = CharSet.Unicode)]
        //public static extern string HandleStringC(string inputStr);

        //[DllImport("FakeDLL.dll", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        //public static extern int HandleStringD(string inputString, StringBuilder outputBuffer, int outputBufferLength);

        [DllImport("FakeDLL.dll", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern int HandleStringE(string inputString, ref StringBuilder outputBuffer);

        [DllImport("FakeDLL.dll", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern int HandleStringF(StringBuilder outputBuffer, int bufferLength);

        static void Main()
        {
            //Console.WriteLine("Testing add...");

            //IntPtr obj = Create(5);

            //int result = AddValue(obj, 10);

            //Console.WriteLine($"AddValue Result is {result}");

            int resultInt = 0;
            string inputStr = "1234567890";

            int outputBufferLength = 1000;
            StringBuilder outputBuffer = new(outputBufferLength);

            //int resultInt = HandleStringD(inputStr, outputBuffer, outputBufferLength);

            //Console.WriteLine($"HandleStringD requested {outputBufferLength} bytes, result is {resultInt}, output buffer is '{outputBuffer}'");

            //int resultInt = HandleStringE(inputStr, ref outputBuffer);

            //Console.WriteLine($"HandleStringE result is {resultInt}, output buffer is '{outputBuffer}'");

            outputBuffer = new(outputBufferLength);

            resultInt = HandleStringF(outputBuffer, 20);

            Console.WriteLine($"HandleStringF result is {resultInt}, output buffer is '{outputBuffer}'");
        }
    }
}



