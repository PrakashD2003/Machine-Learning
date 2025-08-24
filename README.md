# Machine Learning Study Repository

This repository is a **comprehensive collection of Jupyter notebooks** documenting my journey through **machine learning concepts**. It is organised into clear modules covering **automated exploratory data analysis (EDA)**, **supervised learning**, and **unsupervised learning**. Each notebook contains code, visualisations and commentary that illustrate how to load data, prepare it for modelling, train algorithms, evaluate performance, and tune hyper-parameters.&#x20;

---

## 🚀 Quick Overview

* **Goal:** Build a hands-on reference for core machine-learning techniques using Python and scikit-learn. The notebooks show how to explore datasets, train predictive models, and perform clustering from scratch.
* **Pipeline / Workflow Steps:**

  * **Data Loading & Exploration** – Import datasets, inspect columns, and visualise distributions.
  * **Pre-processing & Feature Scaling** – Clean data, encode labels, split into training/testing sets, and scale features. Feature scaling notebooks demonstrate **normalization (Min-Max scaling)** and **standardization (Z-score scaling)** to ensure all features contribute equally to the model.
  * **Model Training** – Apply regression/classification algorithms such as **linear regression**, **logistic regression**, and **decision trees**.
  * **Evaluation & Tuning** – Calculate metrics, inspect coefficients/intercepts, and use **GridSearchCV** for hyper-parameter tuning.
  * **Unsupervised Clustering** – Generate synthetic data and perform **K-Means**, **hierarchical clustering**, and **DBSCAN**.
* **Tech Stack:** Python, Jupyter notebooks, NumPy, pandas, Matplotlib, Seaborn, scikit-learn.
* **Highlights:** Demonstrates automated EDA tools (pandas profiling, Autoviz, Sweetviz, Dtale), feature scaling via normalization and standardization, regression with multiple predictors, classification on real datasets (e.g. Algerian forest fire), decision tree pruning, synthetic cluster generation, and dimensionality reduction with PCA.
* **Feature Engineering:** Introduces feature scaling techniques (normalization and standardization) using **Min-Max** and **Z-score** formulas to ensure equal contribution of features.&#x20;

---

## 📂 Repository Structure

* `Machine Learning/EDA/` — Notebooks for data exploration and anomaly detection. Includes automated EDA tools and methods like Isolation Forest, DBSCAN & Local Outlier Factor.
* `Machine Learning/Supervised Learning/` — Projects on regression and classification. Contains notebooks for simple linear regression, multiple linear regression, polynomial regression, logistic regression with hyper-parameter tuning, and decision tree classifiers (post-pruning & pre-pruning).
* `Machine Learning/Unsupervised Learning/` — Clustering notebooks covering **K-Means**, hierarchical clustering with **AgglomerativeClustering**, and **DBSCAN**.
* `Machine Learning/Feature Engineering/Feature Scaling/` — Notebooks demonstrating feature scaling techniques. Includes **Normalization** and **Standardization** notebooks explaining how to rescale features using **Min-Max** and **Z-score** formulas.
* `Datasets/` — Placeholder for datasets used in the notebooks. Some notebooks load built-in datasets (e.g. Iris, Wine, synthetic blobs).
* `.gitattributes`, `.gitignore` — Standard Git configuration files.&#x20;

---

## ⚙️ How It Works

### Automated EDA

* **Pandas Profiling, Autoviz & Sweetviz:** EDA notebooks generate interactive reports. Data is loaded from CSVs or built-in datasets, displayed via `df.head()`, and then passed to the profiling tool to automatically compute summary statistics and visualisations.
* **Anomaly Detection:** Additional notebooks apply **Isolation Forest**, **DBSCAN**, and **Local Outlier Factor** to identify unusual observations. Example: the DBSCAN anomaly detection notebook shows how density-based clustering can detect outliers without labels.&#x20;

### Feature Engineering – Scaling

* **Normalization (Min-Max Scaling):** Rescale features to a fixed range $0, 1$ using
  `x' = (x − x_min) / (x_max − x_min)`.
  Normalization ensures that all features contribute equally to the model. Demonstrated with `MinMaxScaler` from scikit-learn.&#x20;
* **Standardization (Z-Score Scaling):** Transform features to have zero mean and unit variance using
  `x' = (x − μ) / σ`.
  Standardization improves numerical stability for algorithms sensitive to feature magnitude. Demonstrated with `StandardScaler`.&#x20;

### Regression Projects

* **Simple Linear Regression – Height vs Weight:** Reads a CSV of heights/weights, splits train/test, fits `LinearRegression`, and interprets coefficient & intercept. Includes a scatter plot of the relationship.&#x20;
* **Multiple & Polynomial Regression:** Uses synthetic/real datasets to illustrate how adding predictors or polynomial features affects flexibility; computes **R²** and plots predicted vs actual.&#x20;

### Classification & Hyper-parameter Tuning

* **Algerian Forest Fire Dataset:** Load, preprocess, train, and compare models on a real-world classification problem.&#x20;
* **Logistic Regression:** Loads Iris via seaborn, scales features, and fits `LogisticRegression`. Includes a markdown explainer for **GridSearchCV** and its parameters.&#x20;
* **Decision Trees:** Demonstrates post- and pre-pruning. Imports `DecisionTreeClassifier`, fits the model, visualises the tree, and adjusts pruning parameters (e.g., `max_depth`) to control overfitting.&#x20;

### Unsupervised Clustering

* **K-Means:** Generates synthetic data with `make_blobs`, applies **K-Means**, and uses the inertia (elbow method) to choose *k*.&#x20;
* **Hierarchical Clustering:** Standardises Iris data, reduces with **PCA**, and performs **agglomerative clustering**; includes a dendrogram.&#x20;
* **DBSCAN:** Creates a non-linear dataset with `make_moons` and compares **DBSCAN** to **K-Means**, highlighting arbitrary-shape clusters.&#x20;

---

## ▶️ Running the Project

**Clone the repository**

```bash
git clone https://github.com/PrakashD2003/Machine-Learning.git
cd Machine-Learning/Machine\ Learning
```

**Set up a Python environment** (recommended: virtualenv)

```bash
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
```

The root `requirements.txt` lists core packages such as pandas, NumPy, Matplotlib, Seaborn, and scikit-learn.&#x20;

**Launch Jupyter Notebook**

```bash
jupyter notebook
```

Open the desired notebook in your browser and run cells sequentially. Some notebooks may require downloading datasets into the `Datasets/` folder.&#x20;

---

## 📊 Key Learnings

* **Data Exploration:** Automated EDA tools quickly summarise datasets, revealing distributions, correlations, and missing values.
* **Model Building:** Regression notebooks reinforce linear model fitting and the importance of inspecting coefficients and intercepts.
* **Hyper-parameter Tuning:** `GridSearchCV` performs exhaustive search with cross-validation and returns the best parameters.
* **Tree-Based Methods:** Pruning controls model complexity and reduces overfitting.
* **Dimensionality Reduction & Clustering:** **PCA** reduces dimensionality for clustering; **K-Means**, **Hierarchical**, and **DBSCAN** illustrate complementary clustering strategies.
* **Feature Scaling:** **Normalization** and **Standardization** bring features onto comparable scales, preventing large-magnitude features from dominating models.&#x20;

---
## 🙌 Closing Notes

Thanks for exploring this repository! It serves as a learning diary and a reference for fundamental machine-learning workflows. Feel free to open issues or pull requests with suggestions or contributions.&#x20;

---

## Notebook Links

* **Normalization.ipynb** — [https://github.com/PrakashD2003/Machine-Learning/blob/main/Machine%20Learning/Feature%20Engineering/Feature%20Scaling/Normalization.ipynb](https://github.com/PrakashD2003/Machine-Learning/blob/main/Machine%20Learning/Feature%20Engineering/Feature%20Scaling/Normalization.ipynb)
* **Standardization.ipynb** — [https://github.com/PrakashD2003/Machine-Learning/blob/main/Machine%20Learning/Feature%20Engineering/Feature%20Scaling/Standardization.ipynb](https://github.com/PrakashD2003/Machine-Learning/blob/main/Machine%20Learning/Feature%20Engineering/Feature%20Scaling/Standardization.ipynb)
* **1\_Project\_Simple\_Linear\_Regression\_Height\_Vs\_Weight..ipynb** — [https://github.com/PrakashD2003/Machine-Learning/blob/main/Machine%20Learning/Supervised%20Learning/1\_Project\_Simple\_Linear\_Regression\_Height\_Vs\_Weight..ipynb](https://github.com/PrakashD2003/Machine-Learning/blob/main/Machine%20Learning/Supervised%20Learning/1_Project_Simple_Linear_Regression_Height_Vs_Weight..ipynb)
* **6\_Logistic\_Regression\_Binary\_Classification.ipynb** — [https://github.com/PrakashD2003/Machine-Learning/blob/main/Machine%20Learning/Supervised%20Learning/6\_Logistic\_Regression\_Binary\_Classification.ipynb](https://github.com/PrakashD2003/Machine-Learning/blob/main/Machine%20Learning/Supervised%20Learning/6_Logistic_Regression_Binary_Classification.ipynb)
* **7\_Decision\_Tree\_Classifier\_Post\_Pruning.ipynb** — [https://github.com/PrakashD2003/Machine-Learning/blob/main/Machine%20Learning/Supervised%20Learning/7\_Decision\_Tree\_Classifier\_Post\_Pruning.ipynb](https://github.com/PrakashD2003/Machine-Learning/blob/main/Machine%20Learning/Supervised%20Learning/7_Decision_Tree_Classifier_Post_Pruning.ipynb)
* **13\_K\_Means\_Clustering.ipynb** — [https://github.com/PrakashD2003/Machine-Learning/blob/main/Machine%20Learning/Unsupervised%20Learning/13\_K\_Means\_Clustering.ipynb](https://github.com/PrakashD2003/Machine-Learning/blob/main/Machine%20Learning/Unsupervised%20Learning/13_K_Means_Clustering.ipynb)
* **14\_Hierarchical\_Clustering.ipynb** — [https://github.com/PrakashD2003/Machine-Learning/blob/main/Machine%20Learning/Unsupervised%20Learning/14\_Hierarchical\_Clustering.ipynb](https://github.com/PrakashD2003/Machine-Learning/blob/main/Machine%20Learning/Unsupervised%20Learning/14_Hierarchical_Clustering.ipynb)
* **15\_DBSCAN\_CLustering.ipynb** — [https://github.com/PrakashD2003/Machine-Learning/blob/main/Machine%20Learning/Unsupervised%20Learning/15\_DBSCAN\_CLustering.ipynb](https://github.com/PrakashD2003/Machine-Learning/blob/main/Machine%20Learning/Unsupervised%20Learning/15_DBSCAN_CLustering.ipynb)&#x20;
