# Mini-shell# 

Ce projet est un mini-shell simple développé en langage C. Il permet d’exécuter des commandes basiques en ligne de commande via une interface minimaliste.

---

## Fonctionnalités principales

- Affichage d’un prompt `mini-shell>`  
- Lecture et exécution de commandes Unix classiques (`ls`, `pwd`, `echo`, etc.)  
- Support de la commande interne `exit` pour quitter le shell  
- Utilisation de `fork()` et `execvp()` pour lancer les commandes dans un processus fils  
- Gestion basique des erreurs d’exécution  

---

## Contenu du projet

- `src/minishell.c` : code source principal du mini-shell  
- `docs/` : captures d’écran illustrant le fonctionnement du mini-shell  
- `docs/demo.mp4` : enregistrement vidéo montrant une démonstration de l’exécution du mini-shell  
- `README.md` : ce fichier de présentation  

---

## Installation

### Prérequis

- Un système Linux (ex : Ubuntu)  
- Un compilateur C (`gcc`) installé  

### Compilation

Ouvrir un terminal dans le dossier `src/` et compiler avec :

```bash
gcc minishell.c -o minishell
