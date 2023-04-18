#include <CapacitiveSensor.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

AudioSynthWaveform       waveform1;      //xy=575,53.25
AudioSynthWaveform       waveform2;      //xy=591,389.25
AudioSynthWaveform       waveform3;      //xy=607,764.25
AudioSynthWaveform       waveform4;      //xy=626,1162.25
AudioSynthWaveformSine   sine1;          //xy=649,115.25
AudioSynthWaveformSine   sine2;          //xy=650,183.25
AudioSynthWaveformSine   sine3;          //xy=666,457.25
AudioSynthWaveformSine   sine4;          //xy=668,526.25
AudioSynthWaveformSine   sine5;          //xy=694,832.25
AudioSynthWaveformSine   sine6;          //xy=697,895.25
AudioSynthWaveformSine   sine7;          //xy=715,1259.25
AudioSynthWaveformSine   sine8;          //xy=715,1329.25
AudioMixer4              mixer2;         //xy=817,492.25
AudioMixer4              mixer1;         //xy=829,166.25
AudioMixer4              mixer3;         //xy=840,858.25
AudioMixer4              mixer4;         //xy=911,1319.25
AudioSynthWaveformDc     dc1;            //xy=963,625.25
AudioSynthWaveform       waveform5;      //xy=968,568.25
AudioFilterStateVariable filter2;        //xy=983,396.25
AudioFilterStateVariable filter3;        //xy=1000,764.25
AudioFilterStateVariable filter1;        //xy=1003,51.25
AudioFilterStateVariable filter4;        //xy=1020,1159.25
AudioMixer4              mixer6;         //xy=1149,580.25
AudioEffectMultiply      multiply1;      //xy=1282,485.25
AudioPlaySdWav           playSdWav2;     //xy=1335,1334
AudioSynthNoiseWhite     noise1;         //xy=1407,1043
AudioPlaySdWav           playSdWav1;     //xy=1407,1217
AudioEffectGranular      granular1;      //xy=1510,1330
AudioFilterStateVariable filterChimes; //xy=1572,1221
AudioMixer4              mixer5;         //xy=1612,562.25
AudioFilterStateVariable filterSnare; //xy=1637,1042
AudioFilterStateVariable filterGranular; //xy=1662,1343
AudioEffectEnvelope      envelopeChimes;      //xy=1745,1224
AudioSynthSimpleDrum     drum1;          //xy=1815,1119
AudioEffectEnvelope      envelopeSnare;      //xy=1831,1040
AudioEffectEnvelope      envelopeGranular;      //xy=1917.5000305175781,1339.5000190734863
AudioMixer4              mixerNonDrone;  //xy=2170.500030517578,1077.0000171661377
AudioOutputAnalogStereo  dacs1;          //xy=2313.500030517578,666.7500085830688
AudioConnection          patchCord1(waveform1, 0, filter1, 0);
AudioConnection          patchCord2(waveform2, 0, filter2, 0);
AudioConnection          patchCord3(waveform3, 0, filter3, 0);
AudioConnection          patchCord4(waveform4, 0, filter4, 0);
AudioConnection          patchCord5(sine1, 0, mixer1, 0);
AudioConnection          patchCord6(sine2, 0, mixer1, 1);
AudioConnection          patchCord7(sine3, 0, mixer2, 0);
AudioConnection          patchCord8(sine4, 0, mixer2, 1);
AudioConnection          patchCord9(sine5, 0, mixer3, 0);
AudioConnection          patchCord10(sine6, 0, mixer3, 1);
AudioConnection          patchCord11(sine7, 0, mixer4, 0);
AudioConnection          patchCord12(sine8, 0, mixer4, 1);
AudioConnection          patchCord13(mixer2, 0, filter2, 1);
AudioConnection          patchCord14(mixer1, 0, filter1, 1);
AudioConnection          patchCord15(mixer3, 0, filter3, 1);
AudioConnection          patchCord16(mixer4, 0, filter4, 1);
AudioConnection          patchCord17(dc1, 0, mixer6, 1);
AudioConnection          patchCord18(waveform5, 0, mixer6, 0);
AudioConnection          patchCord19(filter2, 0, multiply1, 0);
AudioConnection          patchCord20(filter3, 0, mixer5, 2);
AudioConnection          patchCord21(filter1, 0, mixer5, 0);
AudioConnection          patchCord22(filter4, 0, mixer5, 3);
AudioConnection          patchCord23(mixer6, 0, multiply1, 1);
AudioConnection          patchCord24(multiply1, 0, mixer5, 1);
AudioConnection          patchCord25(playSdWav2, 0, granular1, 0);
AudioConnection          patchCord26(noise1, 0, filterSnare, 0);
AudioConnection          patchCord27(playSdWav1, 0, filterChimes, 0);
AudioConnection          patchCord28(granular1, 0, filterGranular, 0);
AudioConnection          patchCord29(filterChimes, 0, envelopeChimes, 0);
AudioConnection          patchCord30(mixer5, 0, dacs1, 0);
AudioConnection          patchCord31(filterSnare, 0, envelopeSnare, 0);
AudioConnection          patchCord32(filterGranular, 0, envelopeGranular, 0);
AudioConnection          patchCord33(envelopeChimes, 0, mixerNonDrone, 2);
AudioConnection          patchCord34(drum1, 0, mixerNonDrone, 1);
AudioConnection          patchCord35(envelopeSnare, 0, mixerNonDrone, 0);
AudioConnection          patchCord36(envelopeGranular, 0, mixerNonDrone, 3);
AudioConnection          patchCord37(mixerNonDrone, 0, dacs1, 1);




CapacitiveSensor   cs_33_32_knife = CapacitiveSensor(33, 32);       
CapacitiveSensor   cs_33_31_fork = CapacitiveSensor(37, 31);       
CapacitiveSensor   cs_34_30_spoon = CapacitiveSensor(34, 30);      
CapacitiveSensor   cs_34_29_plate = CapacitiveSensor(38, 29);      
CapacitiveSensor   cs_35_28_snare = CapacitiveSensor(35, 28);       
CapacitiveSensor   cs_35_27_drum = CapacitiveSensor(39, 27);       
CapacitiveSensor   cs_36_26_chimes = CapacitiveSensor(36, 26);     
CapacitiveSensor   cs_36_25_granular = CapacitiveSensor(24, 25);       




#define SDCARD_CS_PIN    BUILTIN_SDCARD
#define SDCARD_MOSI_PIN  11 
#define SDCARD_SCK_PIN   13  



#define GRANULAR_MEMORY_SIZE 25600 
int16_t granularMemory[GRANULAR_MEMORY_SIZE];



#define numUtensils 8



int readDuration = 250;
unsigned long lastReadTime = 0;



long csThreshold[numUtensils] = {5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000}; 


int attackMin = 10;
int attackMax = 100;
int holdMin = 100;       // parameters for random synth envelope generation
int holdMax = 300;
int decayMin = 5;
int decayMax = 100;


int filterCutoffLatched = 250;
float filterQLatched  = 1.7;
float filterOctaveControlLatched = 2;         // parameters for random synth filter generation
int filterCutoffUnlatched = 475;
float filterQUnlatched  = 1.7;
float filterOctaveControlUnlatched = 1;



int lastLatchState[numUtensils] = { };
int utensilPin[numUtensils] = {A7, A9, A5, A3};
long utensilValue[numUtensils] = { };
int latchedUtensilValue[numUtensils] = { };


float scaleFrequency[18] = {87.31, 98.00, 110.00, 123.47, 130.81, 146.83, 164.81, 174.61, 196.00, 220.00, 246.94, 261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88};


int stepDuration = 100;
unsigned long lastStepTime[numUtensils] = { };


int modifier = 0;
int constrainedScaleStep = 0;





// SNARE

int snareFilterFrequencyMin = 100;
int snareFilterFrequencyMax = 1200;

int snareAttackMin = 5;
int snareAttackMax = 50;

int snareDecayMin = 500;
int snareDecayMax = 1000;

int snareStepDurationMin = 100;
int snareStepDurationMax = 10000;

int currentSnareStepDuration = 500;
unsigned long lastSnareStepTime = 0;

int snareLevelMin = 60;
int snareLevelMax = 80;


// DRUM

int drumFrequencyMin = 100;
int drumFrequencyMax = 200;

int drumLengthMin = 50;
int drumLengthMax = 3000;

float drumSecondMixLevel = 0.2;

float drumPitchModMin = 3;
float drumPitchModMax = 7;

int drumStepDurationMin = 500;
int drumStepDurationMax = 20000;

int currentDrumStepDuration = 500;
unsigned long lastDrumStepTime = 0;

int drumLevelMin = 20;
int drumLevelMax = 75;



// CHIMES

int chimesFilterFrequencyMin = 500;
int chimesFilterFrequencyMax = 2000;

int chimesStepDurationMin = 100;
int chimesStepDurationMax = 700;

int currentChimesStepDuration = 500;
unsigned long lastChimesStepTime = 0;

int chimesLevelMin = 60;
int chimesLevelMax = 85;



// GRANULAR

float granularSpeedMin = 0.25;
float granularSpeedMax = 4.0;

int granularGrainLengthMin = 30;
int granularGrainLengthMax = 180;

int granularFilterFrequencyMin = 600;
int granularFilterFrequencyMax = 5000;

int granularStepDurationMin = 100;
int granularStepDurationMax = 700;

int currentGranularStepDuration = 300;
unsigned long lastGranularStepTime = 0;

int granularLevelMin = 60;
int granularLevelMax = 80;






void setup() {

  
  Serial.begin(9600);

  AudioMemory(100);

  cs_33_32_knife.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_33_31_fork.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_34_30_spoon.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_34_29_plate.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_35_28_snare.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_35_27_drum.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_36_26_chimes.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_36_25_granular.set_CS_AutocaL_Millis(0xFFFFFFFF);


  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }


  granular1.begin(granularMemory, GRANULAR_MEMORY_SIZE);


  waveform1.begin(0.1, 220.00, WAVEFORM_SQUARE);
  waveform2.begin(0.1, 220.00, WAVEFORM_SQUARE);    // initialize synth voices
  waveform3.begin(0.1, 220.00, WAVEFORM_TRIANGLE);
  waveform4.begin(0.1, 220.00, WAVEFORM_TRIANGLE);



  sine1.amplitude(0.5);
  sine2.amplitude(0.5);
  sine3.amplitude(0.5);
  sine4.amplitude(0.5);
  sine5.amplitude(0.5);
  sine6.amplitude(0.5);
  sine7.amplitude(0.5);
  sine8.amplitude(0.5);
                              //initialize LFOs
  sine1.frequency(0.1);
  sine2.frequency(0.2);
  sine3.frequency(0.075);
  sine4.frequency(0.225);
  sine5.frequency(0.05);
  sine6.frequency(0.15);
  sine7.frequency(0.25);
  sine8.frequency(0.0112);

}





void loop() {


  utensilValue[0] = cs_33_32_knife.capacitiveSensor(10);     // read CapSense
  utensilValue[1] = cs_33_31_fork.capacitiveSensor(10);
  utensilValue[2] = cs_34_30_spoon.capacitiveSensor(10);
  utensilValue[3] = cs_34_29_plate.capacitiveSensor(10);
  utensilValue[4] = cs_35_28_snare.capacitiveSensor(10);
  utensilValue[5] = cs_35_27_drum.capacitiveSensor(10);
  utensilValue[6] = cs_36_26_chimes.capacitiveSensor(10);            
  utensilValue[7] = cs_36_25_granular.capacitiveSensor(10);





  for (int i = 0; i < numUtensils; i++) {     

    if (utensilValue[i] > csThreshold[i]) {  
      unlatch(i);
      lastLatchState[i] = 1;
    }

    else {                                   
      if (lastLatchState[i] == 1) {

        delay(30);

        latchedUtensilValue[i] = random(0, 7);    // assign resting pitch for drone upon reentry into "Latched" state
      }

      lastLatchState[i] = 0;

      latch(i);

    }
  }
}






void latch(int latchChannel) {

  if (latchChannel == 0) {
    filter1.frequency(filterCutoffLatched);
    filter1.resonance(filterQLatched);
    filter1.octaveControl(filterOctaveControlLatched);
    waveform1.amplitude(0.03);
    waveform1.frequency(scaleFrequency[latchedUtensilValue[0] + 11]);


  }

  else if (latchChannel == 1) {
    filter2.frequency(filterCutoffLatched);
    filter2.resonance(filterQLatched);
    filter2.octaveControl(filterOctaveControlLatched);
    dc1.amplitude(1.0);
    waveform5.amplitude(0.0);
    waveform2.amplitude(0.03);
    waveform2.frequency(scaleFrequency[latchedUtensilValue[1] + 11]);


  }

  else if (latchChannel == 2) {
    filter3.frequency(filterCutoffLatched);
    filter3.resonance(filterQLatched);
    filter3.octaveControl(filterOctaveControlLatched);
    waveform3.amplitude(0.05);
    waveform3.frequency(scaleFrequency[latchedUtensilValue[2] + 4]);


  }

  else if (latchChannel == 3) {
    filter4.frequency(100);
    filter4.resonance(filterQLatched);
    filter4.octaveControl(2.5);
    waveform4.amplitude(0.2);
    waveform4.frequency(scaleFrequency[latchedUtensilValue[3]]);


  }
}





void unlatch(int channel) {

  if (channel == 0) {       // KNIFE ONE

    if (millis() > lastStepTime[0] + stepDuration) {
      lastStepTime[0] = millis();

      filter1.frequency(3000);
      filter1.resonance(filterQUnlatched);
      filter1.octaveControl(filterOctaveControlUnlatched);


      if (random(0, 4) < 3) {

        modifier = random(-4, 4) + 10;
        constrainedScaleStep = constrain(modifier, 0, 14);
        waveform1.begin(WAVEFORM_SQUARE);
        waveform1.amplitude(0.03);
        waveform1.frequency(scaleFrequency[constrainedScaleStep]);

        
      }
    }
  }



  if (channel == 1) {     // FORK ONE

    if (millis() > lastStepTime[1] + stepDuration) {
      lastStepTime[1] = millis();

      filter2.frequency(650);
      filter2.resonance(filterQUnlatched);
      filter2.octaveControl(0.5);



      if (random(0, 4) < 3) {

        modifier = random(-4, 4) + 10;
        constrainedScaleStep = constrain(modifier, 0, 14);
        dc1.amplitude(0.0);
        waveform5.begin(1.0, 9.0, WAVEFORM_TRIANGLE);
        waveform2.amplitude(0.15);
        waveform2.frequency(scaleFrequency[constrainedScaleStep]);

      }
    }
  }



  if (channel == 2) {     // SPOON ONE
    
    if (millis() > lastStepTime[2] + stepDuration) {
      lastStepTime[2] = millis();

      filter3.frequency(650);
      filter3.resonance(5.0);
      filter3.octaveControl(filterOctaveControlUnlatched);


      if (random(0, 4) < 3) {

        modifier = random(-4, 4) + 6;
        constrainedScaleStep = constrain(modifier, 0, 17);
        waveform3.amplitude(0.25);
        waveform3.frequency(scaleFrequency[constrainedScaleStep]);

      }
    }
  }





  if (channel == 3) {     // PLATE ONE

    if (millis() > lastStepTime[3] + stepDuration) {
      lastStepTime[3] = millis();

      filter4.frequency(filterCutoffUnlatched);
      filter4.resonance(filterQUnlatched);
      filter4.octaveControl(filterOctaveControlUnlatched);


      if (random(0, 4) < 3) {

        modifier = random(0, 5);
        constrainedScaleStep = constrain(modifier, 0, 5);
        waveform4.amplitude(0.3);
        waveform4.frequency(scaleFrequency[constrainedScaleStep]);


      }
    }
  }





  if (channel == 4) {       //SPOON TWO

    if (millis() > lastStepTime[4] + stepDuration) {
      lastStepTime[4] = millis();


      if (random(0, 4) < 3) {

        float currentSnareLevel = random(snareLevelMin, snareLevelMax) / 100.0;
        mixerNonDrone.gain(0, currentSnareLevel);
        noise1.amplitude(0.4);
        filterSnare.frequency(random(snareFilterFrequencyMin, snareFilterFrequencyMax));
        filterSnare.resonance(5.0);
        envelopeSnare.attack(random(snareAttackMin, snareAttackMax));
        envelopeSnare.decay(random(snareDecayMin, snareDecayMax));
        envelopeSnare.sustain(0);
        envelopeSnare.noteOn();

      }
    }
  }



  if (channel == 5) {       // PLATE TWO

    if (millis() > lastStepTime[5] + stepDuration) {
      lastStepTime[5] = millis();


      if (random(0, 4) < 3) {

        float currentDrumLevel = random(drumLevelMin, drumLevelMax) / 100.0;
        mixerNonDrone.gain(1, currentDrumLevel);
        drum1.frequency(random(drumFrequencyMin, drumFrequencyMax));
        drum1.length(currentDrumStepDuration - 10);
        drum1.secondMix(drumSecondMixLevel);
        float drumPitchMod = random(drumPitchModMin, drumPitchModMax) / 10.0;
        drum1.pitchMod(drumPitchMod);
        Serial.println(drumPitchMod);
        drum1.noteOn();

      }
    }
  }



  if (channel == 6) {       // FORK TWO

    if (playSdWav1.isPlaying() == 0) {
      playSdWav1.play("CHIMESPITCHED.WAV");
      delay(25);
    }
  
  
    if (millis() > lastChimesStepTime + currentChimesStepDuration) {
  
      lastChimesStepTime = millis();
  
      currentChimesStepDuration = currentChimesStepDuration - (currentChimesStepDuration * 0.25);
  
      if (currentChimesStepDuration < 30) {
        currentChimesStepDuration = random(chimesStepDurationMin, chimesStepDurationMax);
  
      }
  
      float currentChimesLevel = random(chimesLevelMin, chimesLevelMax) / 100.0;
      mixerNonDrone.gain(2, currentChimesLevel);
      filterChimes.frequency(random(chimesFilterFrequencyMin, chimesFilterFrequencyMax));
      envelopeChimes.attack(random(snareAttackMin, currentChimesStepDuration / 2));
      envelopeChimes.decay(random(snareDecayMin, currentChimesStepDuration / 2));
      envelopeChimes.sustain(0);
      envelopeChimes.noteOn();
  
    }
  }





  if (channel == 7) {       // KNIFE TWO

    if (playSdWav2.isPlaying() == 0) {
      playSdWav2.play("GRANULAR.WAV");
      delay(25);
    }
  
    if (millis() > lastGranularStepTime + currentGranularStepDuration) {
  
      lastGranularStepTime = millis();
  
      currentGranularStepDuration = currentGranularStepDuration - (currentGranularStepDuration * 0.25);
  
      if (currentGranularStepDuration < 30) {
        currentGranularStepDuration = random(granularStepDurationMin, granularStepDurationMax);
      }
  
      float currentGranularLevel = random(granularLevelMin, granularLevelMax) / 100.0;
      mixerNonDrone.gain(3, currentGranularLevel);
      granular1.setSpeed(random(granularSpeedMin, granularSpeedMax));
      granular1.beginPitchShift(random(granularGrainLengthMin, granularGrainLengthMax));
      filterGranular.frequency(random(granularFilterFrequencyMin, granularFilterFrequencyMax));
      envelopeGranular.attack(random(snareAttackMin, currentGranularStepDuration / 2));
      envelopeGranular.decay(random(snareDecayMin, currentGranularStepDuration / 2));
      envelopeGranular.sustain(0);
      envelopeGranular.noteOn();
  
    }
  }
}
