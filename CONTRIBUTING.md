# Contributing to Subtend
Before contributing to this repository, please thoroughly read these guidelines first. It will make maintenance much easier and developing a much smoother experience. 

All contributions and ideas are welcomed!

## Table of Contents

- [Questions](#questions)
- [Contributing](#contributing)
- [Reporting Bugs](#reporting-bugs)
- [Suggesting Features](#suggesting-features)
- [Improving The Documentation](#improving-the-documentation)
- [Styleguides](#styleguides)
- [Commit Messages](#commit-messages)
- [Creating Branches](#creating-branches)

## Questions

> If you want to ask a question, we assume that you have read the available [Documentation](README.md).

Before asking a question, please first check any existing or closed [Issues](/issues) that could be relevant. If there aren't any existing issues that answered your question, 
please feel free to open an issue:
- Create a new [Issue](/issue/new)
- Use the bug and feature templates provided
- Add as much information and context as possible. This is a crucial step to being able to resolve issues correctly.

We will then look into the issue as soon as possible.

## Contributing

> ### Legal Notice <!-- omit in toc -->
> When contributing to this project, you must agree that you have authored 100% of the content, that you have the necessary rights to the content and that the content you contribute may be provided under the project license.

### Reporting Bugs

#### Before Submitting a Bug Report

Verify that you have collected as much information so others can easily replicate the bug. Please also complete the following steps in advance.

- Make sure that you are using the latest version.
- Verify the issue encountered is actually a bug and not user error (Refer back to the [Documentation](README.md) to ensure your local repository was set up correctly).
- Check if there is already an existing bug report in the [Issues](/issues) section.
- Make sure to research in other communities, such as StackOverflow, to see if the issue has been discussed elsewhere. Use your *Google-Fu*.
- Collect information about the bug:
  - Stack trace (Traceback)
  - OS, Platform and Version (Windows, Linux, macOS, x86, ARM)
  - Version of the interpreter, compiler, SDK, runtime environment, package manager, depending on what seems relevant.
  - Steps to replicate, if possible.
- Check if the bug was introduced recently. Is this bug still present in different branches or releases?

#### How Do I Submit a Good Bug Report?

> You must never report security related issues, vulnerabilities or bugs including sensitive information to the issue tracker, or elsewhere in public. Instead sensitive bugs must be sent by email to the owners of the repository.
<!-- Look into PGP -->

We use GitHub issues to track bugs and errors. If you run into an issue with the project:

- Open an [Issue](/issues/new). (Please do not label the issue as a bug until this has been discussed and confirmed it is one)
- Provide expected behavior and actual behavior.
- Provide steps to reproduce, if possible. Doing this can speed up the process of solving the issue. 
- Include any additional information that seems relevant.

Once it's filed:

- The project team will label the issue accordingly.
- A team member will try to reproduce the issue with your provided steps. If there are no reproduction steps or no obvious way to reproduce the issue, the team will ask you for those steps and mark the issue as `needs-repro`. Bugs with the `needs-repro` tag will not be addressed until they are reproduced.
- If the team is able to reproduce the issue, the team will confirm it in the issue comment chain, and will assign to a team member.

<!-- TODO: we probably want to change these tags -->


### Suggesting Features

This section guides you through submitting a feature suggestion for test, **including completely new features and minor improvements to existing functionality**. Following these guidelines will help maintainers and the community to understand your suggestion and find related suggestions.

#### Before Submitting a Feature

- Make sure that you are using the latest version.
- Perform a [search](/issues) to see if the feature has already been suggested or is being developed. If it already exists, add a relevant comment.
- Find out whether your idea fits with the scope and aims of the project. It's up to you to make a strong case to convince the project's developers of the merits of this feature. Keep in mind that we want features that will be useful to the majority of our users and not just a small subset.

#### How Do I Submit a Good Feature Suggestion?

Enhancement or Feature suggestions are tracked as [GitHub issues](/issues).

- Use a **clear and clean title** for the issue to identify the suggestion.
- Provide a **detailed description of the suggested feature**.
- **Describe the current behavior** and **explain how this behavior would change**. Describe why the suggested behavior would be more beneficial.
- Include any relevant media if related to the gui. You can use [LICEcap](https://www.cockos.com/licecap/) to record relevant Gifs in Windows. You can quickly capture screenshots with the Snipping Tool `Win+Shift+S`.

<!-- We need a feature template to reference here -->

### Improving The Documentation
Updating, improving and correcting the documentation
As the project grows, our documentation will need to as well. To contribute to the documentation:

- Provide references to any **recent features** that are not covered under the current documentation.
- Verify there isn't already an open [issue](/issues) that covers your use case. 
- Try to follow the current format of the documentation being modified.


## Styleguides
### Commit Messages
To make your first commit, please make sure to follow the regex format `Regex`. We follow the [Gitmoji guide](https://gitmoji.dev/) to make browsing through commits easier. 

Example:

| Emoji         | Emoji meaning |
| ------------- | ------------- |
| :bug: `:bug:` | Fix a bug.  |
| :fire: `:fire:`  | Remove code or files.  |
| :memo: `:memo:` | Add or update documentation. |
| :sparkles: `:sparkles:` | Introduce new features. |

Commits should include
- The imperative voice (like a command)
- A short but relevant description of your commit, in the first line, that is limited to 50 characters.
- Additional information that is important to know, after the first line, 72 characters or fewer per line
- A reference to the relevant issue or feature `Ref #{issue number}` , in the last line.  

Example commit: 
```
:fire: remove old files.  
  
Remove files that have been deprecated.  
  
Ref #0
```

### Creating Branches
When creating a branch make sure that the branch:
- Follows the format {issue-number}-{word1}-{word2}-{word3}
    - The issue number must match that of the issue being worked. **One issue per branch.**
    - 3 or fewer words
    - The name should be descriptive of the issue

Example: `1-contribution-guide`