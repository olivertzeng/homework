import os
import rich
from rich.console import Console
from rich.panel import Panel
from rich.markdown import Markdown
from textual import App, Binding, Reactive, UI
from textual.containers import Container, Horizontal
from textual.widgets import Button, FileChooser, Label

console = Console()

class App(App):
    def compose(self):
        yield Container(
            Label("Settings"),
            FileChooser(r"./", "unblock.txt", name="unblock-file"),
            FileChooser(r"./", "block.txt", name="block-file"),
            Label("Output file"),
            FileChooser(r"./", name="output-file"),
            Label("Labels"),
            Label("Newline:"),
            Label("Blocked word:"),
            Label("Parenthesis:"),
            Button("Process"),
            name="settings",
        )

        yield Container(
            Label("Progress"),
            ProgressBar(),
            Label("Result:"),
            Button("Open results"),
            Button("Back"),
            Button("Done"),
            name="progress",
            visible=False,
        )

    @Reactive
    def unblock_file(self):
        return None

    @Reactive
    def block_file(self):
        return None

    @Reactive
    def output_file(self):
        return None

    @Reactive
    def labels(self):
        return {"newline": "", "blocked": "", "parenthesis": ""}

    async def on_button_pressed(self, event: Button.Pressed) -> None:
        if event.button.id == "process":
            await self.process_file()

    async def on_file_chooser_changed(self, event: FileChooser.Changed) ->
None:
        if event.file_chooser.id == "unblock-file":
            self.unblock_file = event.value
            if not os.path.exists(self.unblock_file):
                console.print(
                    "[bold red]Warning:[/bold red] unblock.txt not found.
Are you sure you want to proceed?",
                    style="bold red",
                )
        elif event.file_chooser.id == "block-file":
            self.block_file = event.value
        elif event.file_chooser.id == "output-file":
            self.output_file = event.value

    async def process_file(self) -> None:
        # Implement the file processing logic here
        # For now, just simulate some progress
        for i in range(5):
            await self.update_progress(f"Processing {i+1}/5...")
            await rich.sleep(1)

        self.query_one("#progress").visible = True
        self.query_one("#settings").visible = False

    async def update_progress(self, message: str) -> None:
        progress_bar = self.query_one(ProgressBar)
        progress_bar.update(message)

    async def on_button_pressed_back(self, event: Button.Pressed) -> None:
        self.query_one("#progress").visible = False
        self.query_one("#settings").visible = True

    async def on_button_pressed_done(self, event: Button.Pressed) -> None:
        self.exit()

    async def on_button_pressed_open_results(self, event: Button.Pressed) -> None:
        # Implement opening the results file here
        pass

if __name__ == "__main__":
    App.run(title="CSV Processor")
