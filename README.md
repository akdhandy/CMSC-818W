#  Identifying Liquids through Radiometric Effect and Deep Networks

**CMSC818W**: Introduction to IoT & Mobile Computing _(Semester Project)_

### Abstract: 
> In this report, we propose a lightweight liquid testing system
for categorizing different liquids and detecting adulterants
by analysis through signal passing through liquids. Because
different liquids have very different chemistry compositions,
the light transmitted and scattered through the liquids will
usually produce noticeably spectral signatures. By passing
light of different wavelength through different types of liquids,
our framework is able to measure the attenuation in the
signals created by light transmitting and scattering, and then
do analysis on the measurement by training neural network
models for characterizing and therefore achieving liquid detection
for future liquid inputs. Our system has four important
advantages: the system requires very few customized
hardwares and hardwares being used are very affordable.
Also, our system is highly generalized and can be possibly
used for additional liquids with proper training.Moreover
our system requires no direct contact to measure the signal
attenuation.Lastly, our system provides an identification of
> these liquids with decent accuracy.


### Project Structure: 
````
├── Cicuit Schematics
│   ├── All schematic files
│   ├── 818W_Code_arduino
│   │   ├── 818W_Code.ino
│   └── Adafruit_SI1145
│   │   └── all library files
├── Data
│   ├── Data.zip
│   ├── Data_1.zip
│   ├── Data 2.zip
│   ├── Data 3.zip
│   └── All data files extracted are here
├── DNN_Model_&_Scripts
│   ├── 818W_Project_Classification.ipynb
│   └── serial_comm_data_collection.py
├── Reference_Papers
│   └── All reference papers are here
├── Report_&_Presentation
│   ├── 818W_Project.pdf
│   └── Identifying Liquids through Radiometric Effect and Deep Networks.pptx
├── Results_Distributions
│   └── Heatmaps & data distribution charts are here
````

### Note: 
For more details, please find:

- Project Report [here](./Report_&_Presentation/818W_Project.pdf)!

