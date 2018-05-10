# 10up WPCS Configuration
Composer library to automatically install [PHP_CodeSniffer](https://github.com/squizlabs/PHP_CodeSniffer) and [WPCS](https://github.com/WordPress-Coding-Standards/WordPress-Coding-Standards), and provides a standard default to use.

<p align="center">
<a href="http://10up.com/contact/"><img src="https://10updotcom-wpengine.s3.amazonaws.com/uploads/2016/10/10up-Github-Banner.png" width="850"></a>
</p>

## Installation

The easiest way to install the package is globally, using Composer:

```bash
$ composer global require 10up/phcs-config
```

You can also install the package on a per-project basis:

```bash
$ composer require --dev 10up/phcs-config
```

## Usage

From the command line, run the following:

```bash
$ phpcs path/to/your/project
```

As this is a simple ruleset, the [usual PHP_CodeSniffer](https://github.com/squizlabs/PHP_CodeSniffer/wiki/Usage) commands still apply.
