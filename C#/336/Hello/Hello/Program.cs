using Google.Apis.Drive.v3;
using System;


namespace Hello
{
    class Program
    {

        static DriveService request = new DriveService();
        static void Main(string[] args)
        {
            Console.WriteLine("Hello I'm Poppy!");
            Console.WriteLine("Enter the URL");
            String url= 
                Console.ReadLine();
        //https://drive.google.com/open?id=1bxlZCfz4xFm8oiVa4YUghpGJuM1SVYJS
            var fileId = "1bxlZCfz4xFm8oiVa4YUghpGJuM1SVYJS";
            request.Files.Get(fileId);
            var stream = new System.IO.MemoryStream();

            // Add a handler which will be notified on progress changes.
            // It will notify on each chunk download and when the
            // download is completed or failed.
           /* request.MediaDownloader.ProgressChanged +=
                (IDownloadProgress progress) =>
                {
                    switch (progress.Status)
                    {
                        case DownloadStatus.Downloading:
                            {
                                Console.WriteLine(progress.BytesDownloaded);
                                break;
                            }
                        case DownloadStatus.Completed:
                            {
                                Console.WriteLine("Download complete.");
                                break;
                            }
                        case DownloadStatus.Failed:
                            {
                                Console.WriteLine("Download failed.");
                                break;
                            }
                    }
                };*/
               // request.
            //request.Download(stream);


        }
    }
}
