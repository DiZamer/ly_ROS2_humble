{ config, pkgs, ... }:

{
  # Базовые настройки
  home.username = "${config.home.username}";
  home.homeDirectory = "/home/${config.home.username}";
  home.stateVersion = "24.11";

  nixpkgs.config.allowUnfree = true;

  # Установка пакетов
  home.packages = with pkgs; [
    neofetch
    skopeo            # Для работы с образами контейнеров

    # Python с предустановленными пакетами
    (python312.withPackages (ps: with ps; [
      pandas
      numpy
      matplotlib
      pygame
      pillow
      requests
      tqdm
      ipykernel
      django
      beautifulsoup4
      fastapi
      scrapy
      tkinter
      kivy
      scipy
      scikit-learn
      seaborn
      opencv4
      lightgbm
      plotly
      nltk
      spacy
      bokeh
      psycopg
      python-dateutil
      tzdata
      urllib3
      sqlparse
      unidecode
      pytest
      pyyaml
      charset-normalizer
      idna
      cryptography
      playwright
    ]))
  ];

  # Файлы и директории
  home.file = {
  };

  # Дополнительные настройки для Docker
  home.sessionVariables = {
    PYTHONPATH = "$HOME/.local/lib/python3.12/site-packages:$PYTHONPATH";
  };

  # Настройка bash
  programs.bash = {
    enable = true;
    shellAliases = {
      ll = "ls -l";
      la = "ls -la";
      g = "git";

      # Алиасы для Docker
      dps = "docker ps";
      dcup = "docker-compose up -d";
      dcdown = "docker-compose down";
    };
  };

  # Настройка git
  programs.git = {
    enable = true;

    # Игнорируемые файлы
    ignores = [
      "*.pyc"
      "__pycache__/"
      ".python-version"
      ".DS_Store"
      "*.swp"
      "*.log"
      ".devcontainer/"
      ".vscode/"
    ];
  };

  programs.vscode = {
    enable = true;
    package = pkgs.vscode;

    profiles.default = {
      # Расширения для VS Code
      extensions = with pkgs.vscode-extensions; [
        # Python расширения
        ms-python.python
        ms-python.vscode-pylance
        ms-python.black-formatter
        ms-python.isort

        # Docker расширения
        ms-azuretools.vscode-docker

        # Dev Containers расширение
        ms-vscode-remote.remote-containers

        # Git расширения
        eamodio.gitlens
        github.vscode-pull-request-github
        codezombiech.gitignore

        # Доп. расширения
        bbenoist.nix          # Поддержка Nix
        redhat.vscode-yaml    # YAML поддержка
        ms-vscode.cpptools    # C++ поддержка
        ms-vscode.makefile-tools  # Для Makefile в контейнерах
      ];

      # Настройки VS Code
      userSettings = {
        # Python настройки
        "python.defaultInterpreterPath" = "python3";
        "python.analysis.autoImportCompletions" = true;
        "python.analysis.typeCheckingMode" = "basic";

        # Git настройки
        "git.enableSmartCommit" = true;
        "git.confirmSync" = false;
        "git.autofetch" = true;

        # Docker настройки
        "docker.showStartPage" = false;
        "docker.commands.attach" = "$${containerCommand} exec -it $${containerId} $${shellCommand}";
        "docker.commands.exec" = "$${containerCommand} exec -it $${containerId} $${shellCommand}";
        "docker.commands.logs" = "$${containerCommand} logs -f $${containerId}";
        "docker.commands.run" = "$${containerCommand} run --rm -it $${extraArgs} $${image} $${command}";

        # Dev Containers настройки
        "dev.containers.dockerPath" = "docker";
        "dev.containers.dockerComposePath" = "docker-compose";
        "dev.containers.defaultDevContainerConfig" = {
          "image" = "mcr.microsoft.com/devcontainers/base:ubuntu";
        };
        "dev.containers.copyGitConfig" = true;
        "dev.containers.copyGitCredentials" = true;

        # Terminal настройки для работы с контейнерами
        "terminal.integrated.defaultProfile.linux" = "bash";
        "terminal.integrated.profiles.linux" = {
          "bash" = {
            "path" = "bash";
            "icon" = "terminal-bash";
          };
        };

        # Общие настройки
        "editor.fontSize" = 14;
        "editor.tabSize" = 4;
        "editor.insertSpaces" = true;
        "files.autoSave" = "afterDelay";
        "files.autoSaveDelay" = 1000;
        "terminal.integrated.shell.linux" = "/bin/bash";

        # Настройка темы VSCode
        "workbench.colorTheme" = "Default Light Modern";
        # Настройки для Remote Development
        #"remote.autoForwardPorts" = true;
        #"remote.autoForwardPortsSource" = "output";
        #"remote.extensionKind" = {
          #"ms-vscode-remote.remote-containers" = ["workspace"];
        #};
      };

      # Ключевые сочетания клавиш
      keybindings = [
        {
          key = "ctrl+shift+p";
          command = "workbench.action.quickOpen";
        }
        {
          key = "ctrl+`";
          command = "workbench.action.terminal.toggleTerminal";
        }

        # Горячие клавиши для Dev Containers
        {
          key = "ctrl+shift+`";
          command = "workbench.action.terminal.new";
        }
        {
          key = "ctrl+shift+r r";
          command = "remote-containers.reopenFolderInContainer";
        }
        {
          key = "ctrl+shift+r o";
          command = "remote-containers.reopenVolumeInContainer";
        }
      ];
    };
  };

  # Позволяет Home Manager устанавливать и администрировать себя
  programs.home-manager.enable = true;
}
