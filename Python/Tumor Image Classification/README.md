Tumor Image Classification

Google Colab File: https://colab.research.google.com/drive/1KCfWVbJGdK52Y4REu_Eyaw4R-vMOLlXM?usp=sharing

This project explores how **machine learning can support medical specialists** in diagnosing cancer from medical imaging data. Using Convolutional Neural Networks (CNNs), we trained a model to distinguish between **normal colon tissue (NORM)** and **malignant colon tissue (TUM)** with high accuracy.

---

## Motivation
Medical image analysis is essential for diagnosing diseases, but radiologists and pathologists face challenges:  
- Subtle cancer patterns may be invisible to the human eye.  
- Sorting through large volumes of scans is time-consuming.  
- Limited availability of specialists can delay diagnoses.  

Our goal is **not to replace medical experts**, but to assist them by providing a tool that delivers consistent, accurate results.

---

## Dataset  
- **Source:** Colon tissue dataset from [Zenodo]( https://zenodo.org/records/1214456)  
  - 17,598 images total  
  - Two classes:  
    - **NORM** = normal colon lining (~8,700 images)  
    - **TUM** = malignant colon tissue (~8,800 images)  
  - Images pre-scaled to **224 × 224 pixels**  

Data split:  
- 80% training (~14,000 images)  
- 20% testing (~3,500 images)  

---

## Preprocessing & Augmentation
To improve generalization, we applied:  
- **Random flips** (horizontal & vertical)  
- **Random rotations**  
- **Random zooms (±10%)**  
- **Random contrast adjustments (±20%)**  
- **Gaussian noise injection**  

---

## Model Architecture
- Normalization of pixel values (0–255 → 0–1)  
- 3 convolutional blocks (filters: 32, 64, 128)  
- Batch normalization after each convolution  
- Max-pooling layers  
- Dropout (25% mid-model, 30% before final layer)  
- Flatten → Dense (128) → Output (binary classification)  

**Trainable parameters:** ~4.83M (18.4 MB)  

---

## Training Details
- **Batch size:** 64  
- **Hardware:** Google Colab (with checkpoints to handle RAM issues)  
- **Frameworks:** TensorFlow / Keras  

---

## Results
- **Accuracy:** 94.3%  
- **AUC:** 0.984  
- **Loss:** 0.2468  

Confusion Matrix (TUM = 0, NORM = 1):  
- True Positives: 1531  
- True Negatives: 1601  
- False Negatives: 91  
- False Positives: 296  

**Why this matters**  
- False negatives = undetected cancer → delayed treatment  
- False positives = unnecessary biopsies/surgeries → risk + costs  

---

## Key Takeaways
- Data quality & quantity are **critical** for reliable medical ML.  
- CNNs can complement specialists by providing **faster, more consistent diagnoses**.  
- Ethical considerations (privacy, liability, fairness) remain central to deployment.  
- Future directions:  
  - Expand model to other cancer types  
  - Explore legal & ethical frameworks for medical AI adoption  

---

##  Authors
- Brandon Wong
- Kali Cajala

---