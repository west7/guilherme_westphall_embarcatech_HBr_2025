import numpy as np
from scipy.io.wavfile import write

SAMPLE_RATE = 8000
ADC_MAX_VALUE = 4095
WAV_MAX_AMPLITUDE = 32767

def convert_adc_text_to_wav(txt_file_path, wav_output_path):
    with open(txt_file_path, "r") as f:
        line = f.readline()
        raw_values = list(map(int, line.strip().split(",")))

    adc_data = np.array(raw_values, dtype=np.int32)
    adc_data -= 2048  # Remove offset do microfone

    normalized = adc_data / (ADC_MAX_VALUE / 2)
    wav_data = (normalized * WAV_MAX_AMPLITUDE).astype(np.int16)

    write(wav_output_path, SAMPLE_RATE, wav_data)
    print(f"Arquivo WAV salvo como: {wav_output_path}")

# Exemplo de uso
if __name__ == "__main__":
    convert_adc_text_to_wav("adc.txt", "saida.wav")
