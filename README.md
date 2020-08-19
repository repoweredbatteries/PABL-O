# PABL-O
Project for the Analysis of Battery Lifecycle - opensourced

There are five main components to the PABL-O project. The hardware (EasyEDA), the data collection program (arduino), the data analysis program (R), the collected data files, and the generated reports.

Hardware:
The hardware schematics, BOM, and fabrication files can be found here
https://easyeda.com/julien_9465/universal_tester_v7

Data collection program:
The hardware can be used for cell testing, or data collection. The two modes of operation were in two programs up until now, and we are now working on combining both sets of features. Putting the number of cycles with the rotary encoder to 1 or 2 would prevent the recording of data, making the device function in a cell tester mode for end users. Once enough data has been collected to model outcomes, the predictive model will be part of the cell tester mode to give predictive quality outcomes based on the 1-2 cycles.
To do:
-Add SD card recording code
-Add rotary encoder code
-Create exclusion of SD recording when number of cycles is <=2
-Clean up code
-Improve iterupt routine (sometimes the rotary encoder is non-responsive in the original code that is to be integrated)

Dana analysis program
The data analysis program runs in R and relies on proper formatting of the file names, as well as proper entries in the cell metadata file. This structure will be further defined, but we should expect the cell metadata file to contain
-cell data file name identifier, cell characteristics (chemistry, brand, model, nominal capacity, nominal C ratings, notes for known prior lifecycle use that could help if digging into outliers)
-the data files can be hosted in the git repository, PABL-O reserves the right to sell the cell testing service in which case the data files would belong to the client who paid for testing and the release of data would be at their discression.
-the data analysis program will use markdown to generate automated reports which will be hosted in the git repository
